#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <time.h>
#include <sstream>
using namespace std;
char load = 177;

struct Node
{
    string NAME, PIN, MOBILE, ID, ADDRESS;
    int AMOUNT;
    Node *prev;
    Node *next;
};
class ll
{
private:
    Node *head, *tail;

public:
    ll()
    {
        head = NULL;
    }
    void insert(string N, string I, string A1, string P, string Ph, int A)
    {

        Node *newnode = new Node;
        newnode->NAME = N;
        newnode->PIN = P;
        newnode->MOBILE = Ph;
        newnode->ID = I;
        newnode->AMOUNT = A;
        newnode->ADDRESS = A1;
        newnode->next = NULL;
        newnode->prev = NULL;
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
    }
   
    void Create_New_Account(string N, string I, string A1, string P, string Ph, int A)
    {

        int n;
        ifstream r("count.txt");
        if (r)
        {
            r >> n;
            cout << n;
        }

        r.close();
        ifstream w("user.txt");
        string VL1, VL2, VL3, VL4, VL5;
        int VL6;

        if (n == 6)
            insert(N, I, A1, P, Ph, A);
        else
        {
            for (int i = 6; i < n; i++)
            {

                w >> VL1;
                w >> VL2;
             
              
                w >> VL3;
                w >> VL4;
                w >> VL5;
                w >> VL6;
                insert(VL1, VL2, VL3, VL4, VL5, VL6);
                i = i + 5;
            }
            insert(N, I, A1, P, Ph, A);
        }

        Node *ptr;

        update(ptr);
        w.close();
    }

    void update(Node *obj)
    {
        Node *ptr;
        ptr = obj;
        ptr = head;
        ofstream w("user.txt");
        while (ptr != NULL)
        {

            w << ptr->NAME << endl;
            w << ptr->ID << endl;
            w << ptr->ADDRESS << endl;
            w << ptr->PIN << endl;
            w << ptr->MOBILE << endl;

            w << ptr->AMOUNT << endl;

            ptr = ptr->next;
        }
        w.close();
    }


    void display()
    {
        system("color 2E");
        int n;
        ifstream r("count.txt");
        if (r)
        {
            r >> n;
        }
        else
        {
            cout << "\t\t\t\t\t\t\t\t\t\t"
                 << "                                              " << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t"
                 << "           NO ACCOUNTS TO DISPLAY!      " << endl;
            return;
        }

        r.close();
        ifstream w("user.txt");
        string VL1, VL2, VL3, VL4, VL5;
        int VL6;
        ll ob;
        for (int i = 0; i < n; i++)
        {

            w >> VL1;
            w >> VL2;
            w >> VL3;
            w >> VL4;
            w >> VL5;
            w >> VL6;
            insert(VL1, VL2, VL3, VL4, VL5, VL6);
            i = i + 5;
        }

        Node *ptr;
        ptr = head;
        while (ptr != NULL)
        {
            cout << "\t\t\t\t\t\t\t\t\t\t\t" << load << "                              " << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t\t";
            for (int j = 0; j <= 31; j++)
                cout << load;
            cout << "\n";
            cout << "\t\t\t\t\t\t\t\t\t\t\t" << load << "                              " << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t\t" << load << "                              " << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t\t"
                 << "    NAME : " << ptr->NAME << endl;
            // cout<<"\t\t\t\t"<<"    ID : "<< ptr->PIN_N <<endl;
            cout << "\t\t\t\t\t\t\t\t\t\t\t"
                 << "    MOBILE : " << ptr->MOBILE << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t\t"
                 << "    ADDRESS : " << ptr->ADDRESS << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t\t"
                 << "    AMOUNT : " << ptr->AMOUNT << endl;

            cout << "\t\t\t\t\t\t\t\t\t\t\t" << load << "                              " << load << endl;
            ptr = ptr->next;
        }
    }
    void search(string ID1)
    {
        int n;
        ifstream r("count.txt");
        if (r)
        {
            r >> n;
        }

        r.close();
        ifstream w("user.txt");
        string VL1, VL2, VL3, VL4, VL5;
        int VL6;
        ll ob;
        for (int i = 0; i < n; i++)
        {

            w >> VL1;
            w >> VL2;
            w >> VL3;
            w >> VL4;
            w >> VL5;
            w >> VL6;
            insert(VL1, VL2, VL3, VL4, VL5, VL6);
            i = i + 5;
        }
        int c = 0;
        Node *ptr;
        ptr = head;
        while (ptr != NULL)
        {
            if (ptr->ID == ID1)
            {
                system("cls");
                system("color 5B");
                cout << "\n\n\n\n\n\n";
                cout << "\t\t\t\t\t\t\t\t\t\t\t";
                for (int j = 0; j <= 31; j++)
                    cout << load;
                cout << "\n";
                cout << "\t\t\t\t\t\t\t\t\t\t\t" << load << "                              " << load << endl;
                cout << "\t\t\t\t\t\t\t\t\t\t\t" << load << "  BANKING MANAGEMENT SYSTEM   " << load << endl;
                cout << "\t\t\t\t\t\t\t\t\t\t\t" << load << "                              " << load << endl;
                cout << "\t\t\t\t\t\t\t\t\t\t\t";
                for (int j = 0; j <= 31; j++)
                    cout << load;
                cout << "\n";
                cout << "\t\t\t\t\t\t\t\t\t\t\t" << load << "                              " << load << endl;
                cout << "\t\t\t\t\t\t\t\t\t\t\t" << load << "                              " << load << endl;
                cout << "\t\t\t\t\t\t\t\t\t\t\t" << load << "      ~~~~~~~~~~~~~~~~~~~     " << load << endl;
                cout << "\t\t\t\t\t\t\t\t\t\t\t" << load << "      |      Detail     |     " << load << endl;
                cout << "\t\t\t\t\t\t\t\t\t\t\t" << load << "      ~~~~~~~~~~~~~~~~~~~     " << load << endl;
                cout << "\t\t\t\t\t\t\t\t\t\t\t" << load << "                              " << load << endl;
                cout << "\t\t\t\t\t\t\t\t\t\t\t" << load << "                              " << load << endl;
                cout << "\t\t\t\t\t\t\t\t\t\t\t"
                     << "    NAME : " << ptr->NAME << endl;
                // cout<<"\t\t\t\t"<<"    ID : "<< ptr->PIN_N <<endl;
                cout << "\t\t\t\t\t\t\t\t\t\t\t"
                     << "    MOBILE : " << ptr->MOBILE << endl;
                cout << "\t\t\t\t\t\t\t\t\t\t\t"
                     << "    ADDRESS : " << ptr->ADDRESS << endl;
                cout << "\t\t\t\t\t\t\t\t\t\t\t"
                     << "    AMOUNT : " << ptr->AMOUNT << endl;

                cout << "\t\t\t\t\t\t\t\t\t\t\t" << load << "                              " << load << endl;
                c++;
                cout << "\t\t\t\t\t\t\t\t\t\t\t";
                for (int j = 0; j <= 31; j++)
                    cout << load;
                cout << "\n";
            }

            ptr = ptr->next;
        }
        if (c == 0)
        {
            system("cls");
            system("color 5B");
            cout << "\n\n\n\n\n\n";
            cout << "\t\t\t\t\t\t\t\t\t\t\t";
            for (int j = 0; j <= 31; j++)
                cout << load;
            cout << "\n";
            cout << "\t\t\t\t\t\t\t\t\t\t\t" << load << "                              " << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t\t" << load << "  SORRY THIS ID NOT FOUND     " << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t\t" << load << "                              " << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t\t";
            for (int j = 0; j <= 31; j++)
                cout << load;
            cout << "\n";
        }
        w.close();
    }
    void Withdraw_Amount(string ID1, int New_amount)
    {
        int n;
        ifstream r("count.txt");
        if (r)
        {
            r >> n;
        }

        r.close();
        ifstream w("user.txt");
        string VL1, VL2, VL3, VL4, VL5;
        int VL6;
        ll ob;
        for (int i = 0; i < n; i++)
        {

            w >> VL1;
            w >> VL2;
            w >> VL3;
            w >> VL4;
            w >> VL5;
            w >> VL6;
            insert(VL1, VL2, VL3, VL4, VL5, VL6);
            i = i + 5;
        }

        Node *ptr;
        ptr = head;
        while (ptr != NULL)
        {
            if (ptr->ID == ID1)
            {
                if (ptr->AMOUNT < New_amount)
                {
                    system("cls");
                    system("color 0A");
                    cout << "\n\n\n\n\n\n";
                    cout << "\t\t\t\t\t";
                    for (int i = 0; i <= 31; i++)
                        cout << load;
                    cout << "\n";
                    cout << "\t\t\t\t\t" << load << "                              " << load << endl;
                    cout << "\t\t\t\t\t" << load << "  Sorry! Bank Balance is Low  " << load << endl;
                    cout << "\t\t\t\t\t" << load << "                              " << load << endl;
                    cout << "\t\t\t\t\t";
                    for (int i = 0; i <= 31; i++)
                        cout << load;
                    cout << "\n";
                    getch();
                    system("cls");
                }
                else
                    ptr->AMOUNT = ptr->AMOUNT - New_amount;

                update(ptr);
            }

            ptr = ptr->next;
        }
        search(ID1);
        w.close();
    }
    void Deposit_Amount(string ID1, int New_amount)
    {
        int n;
        ifstream r("count.txt");
        if (r)
        {
            r >> n;
        }

        r.close();
        ifstream w("user.txt");
        string VL1, VL2, VL3, VL4, VL5;
        int VL6;
        ll ob;
        for (int i = 0; i < n; i++)
        {

            w >> VL1;
            w >> VL2;
            w >> VL3;
            w >> VL4;
            w >> VL5;
            w >> VL6;
            insert(VL1, VL2, VL3, VL4, VL5, VL6);
            i = i + 5;
        }

        Node *ptr;
        ptr = head;
        while (ptr != NULL)
        {
            if (ptr->ID == ID1)
            {
                if (ptr->AMOUNT < New_amount)
                {
                    system("cls");
                    system("color 0A");
                    cout << "\n\n\n\n\n\n";
                    cout << "\t\t\t\t\t";
                    for (int i = 0; i <= 31; i++)
                        cout << load;
                    cout << "\n";
                    cout << "\t\t\t\t\t" << load << "                              " << load << endl;
                    cout << "\t\t\t\t\t" << load << "  Sorry! Bank Balance is Low  " << load << endl;
                    cout << "\t\t\t\t\t" << load << "                              " << load << endl;
                    cout << "\t\t\t\t\t";
                    for (int i = 0; i <= 31; i++)
                        cout << load;
                    cout << "\n";
                    getch();
                    system("cls");
                }
                else
                    ptr->AMOUNT = ptr->AMOUNT + New_amount;

                update(ptr);
            }

            ptr = ptr->next;
        }
        search(ID1);
        w.close();
    }
    void close_account(string ID1)
    {
        int n = 0;
        ifstream r("count.txt");
        if (r)
        {

            r >> n;
        }

        r.close();
        ifstream w("user.txt");
        string VL1, VL2, VL3, VL4, VL5;
        int VL6;
        ll ob;
        for (int i = 0; i < n; i++)
        {

            w >> VL1;
            w >> VL2;
            w >> VL3;
            w >> VL4;
            w >> VL5;
            w >> VL6;
            insert(VL1, VL2, VL3, VL4, VL5, VL6);
            i = i + 5;
        }
        w.close();

        Node *ptr;
        ptr = head;
        string my{"user.txt"};
        string t{"temp.txt"};
        ifstream myfile(my);
        ofstream temp(t);

        Node *p = NULL;
        //    cout<<"inside ...";

        while (ptr != NULL)
        {
            //    prev=ptr;
            //    cout<<ID1<<ptr->ID;
            //

            //      prev->next=ptr->next;
            //      delete ptr;

            if (ptr->ID == ID1)
            {

                break;
            }
            ptr = ptr->next;
        }
       
        string i;
        int skip = 0;
        while (getline(myfile, i))
        {

            if ((i != ptr->ID) && !(skip > 0) && (i != ptr->NAME))
            {
                temp << i << endl;
                //cout << i;
            }
            else
            {
                if (skip == 0)
                {
                    skip = 5; // Skip the next two lines also
                }
                else
                {
                    --skip;
                }
            }
        }
        cout << "The record with the id " << ptr->ID << " has been deleted" << endl;
        n = n - 6;
        ofstream r1("count.txt");
        r1 << n;
        r1.close();
        myfile.close();
        temp.close();
        string x = "user.txt";

        // rename(x.c_str(),"ok.txt");
        remove(my.c_str());
        rename(t.c_str(), "user.txt");

        //}
    }
};
class Bank
{
public:
    virtual void loading(string a){

    };

    virtual int mainmenu(){

    };

    virtual bool adminlogin(){

    };

    virtual int adminmenu(){};
    virtual void searchaccount(){};
    virtual void displayaccount(){};

    virtual void createaccount(){};
    virtual bool loginaccount(){};
    virtual int usermenu(){};
    virtual int loginmenu(){};
    virtual void logout(){};
    virtual void withdraw(){};
    virtual void deposit(){};
    virtual void close(){};
    virtual void loan(){};
};
class basefun : public Bank
{
public:
    void loading(string a)

    {
        system("cls");
        system("color 61");
        cout << "\n\n\n\n\n\n\n\n\n\n\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t" << a << endl
             << endl
             << endl;
        load = 6;
        cout << "\t\t\t\t\t\t\t\t\t\t\t";
        for (int i = 0; i <= 35; i++)
            cout << load;
        cout << "\n";

        cout << "\t\t\t\t\t\t\t\t\t\t\t  "
             << "      -------------------     " << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t\t  "
             << "      |    CREATED BY   |     " << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t\t  "
             << "      -------------------     " << endl;
        ;
        cout << "\t\t\t\t\t\t\t\t\t\t\t  "
             << "          SHREYA JAIN       " << endl;

        cout << "\t\t\t\t\t\t\t\t\t\t\t";
        for (int i = 0; i <= 35; i++)
            cout << load;
        cout << "\n";
        for (int i = 0; i < 199; i++)
        {
            Sleep(1);
        }
        system("cls");
        load = 177;
        system("color 3F");
        cout << "\n\n\n\n\n\n\n\n\n\n\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t"
             << "Loading..." << endl
             << endl
             << endl;
        for (int i = 0; i < 209; i++)
        {
            Sleep(15);
            cout << load;
        }

        system("CLS");
    }
    int mainmenu()
    {
        int c;
        do
        {
            system("cls");
            cout << "\n\n";

            cout << "\t\t\t\t\t\t\t\t\t\t";
            for (int i = 0; i <= 33; i++)
                cout << load;
            cout << "\n";
            cout << "\t\t\t\t\t\t\t\t\t\t" << load << "                                " << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t" << load << "                                " << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t" << load << "       ~~~~~~~~~~~~~~~~~~~      " << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t" << load << "       |     Main Menu   |      " << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t" << load << "       ~~~~~~~~~~~~~~~~~~~      " << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t" << load << "                                " << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t" << load << "    [1]  :  Admin Login         " << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t" << load << "    [2]  :  User Registration   " << load << endl;

            cout << "\t\t\t\t\t\t\t\t\t\t" << load << "________________________________" << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t" << load << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t" << load << "      Logout (Press: esc)       " << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t" << load << "________________________________" << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t";
            for (int i = 0; i <= 33; i++)
                cout << load;
            cout << "\n";
            c = getch();
        } while (c != '1' && c != '2' && c != 27);
        return c;
    }
};
class admin : public Bank
{
public:
    bool adminlogin()
    {
        system("cls");
        string id, pin, compare_id, compare_pin;
        char password;
        cout << "\n\n";

        cout << "\t\t\t\t\t\t\t\t\t\t";

        cout << "\n";

        cout << "\t\t\t\t\t\t\t\t\t\t"
             << "       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~      " << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t"
             << "       |    BANK MANAGEMENT SYSTEM    |     " << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t"
             << "       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~      " << endl;

        cout << "\n";

        cout << "\t\t\t\t\t\t\t\t\t\t"
             << "                                              " << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t"
             << "       Please enter your id and password      " << endl;

        cout << "\t\t\t\t\t\t\t\t\t\t"
             << "           for login this Software            " << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t"
             << "                                              " << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t"
             << "                                              " << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t";
        for (int i = 0; i <= 47; i++)
            cout << load;
        cout << "\n";

        ifstream rd("adminlogin.txt");
        if (!rd.is_open())
        {
            ofstream wrt("adminlogin.txt");
            wrt << "root\n";
            wrt << "123";
        }
        else
        {
            rd >> compare_id;
            rd >> compare_pin;
            cout << "\n\t\t\t\t\t  User ID:   ";
            cin >> id;
            cout << "\t\t\t\t\t      PIN:   ";

            while (password != 13)
            {
                if (password >= 48 && password <= 57)
                {
                    pin.push_back(password);
                    cout << '*';
                }
                password = getch();
            }
        }

        if (id == compare_id && pin == compare_pin)
            return true;
        else
            return false;
    }
    int adminmenu()
    {
        system("color E5");
        int c;
        do
        {
            system("cls");

            cout << "\n\n";

            cout << "\t\t\t\t\t\t\t\t\t\t";
            for (int i = 0; i <= 33; i++)
                cout << load;
            cout << "\n";
            cout << "\t\t\t\t\t\t\t\t\t\t" << load << "                                " << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t" << load << "                                " << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t" << load << "       ~~~~~~~~~~~~~~~~~~~      " << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t" << load << "       |  Admin Account  |      " << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t" << load << "       ~~~~~~~~~~~~~~~~~~~      " << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t" << load << "                                " << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t" << load << "    [1]  :  Search account      " << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t" << load << "    [2]  :  Display account     " << load << endl;

            cout << "\t\t\t\t\t\t\t\t\t\t" << load << "________________________________" << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t" << load << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t" << load << "       Back  (<-Backspace)      " << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t" << load << "________________________________" << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t";
            for (int i = 0; i <= 33; i++)
                cout << load;
            cout << "\n";
            c = getch();
        } while (c != '1' && c != '2' && c != 8);
        return c;
    }
    void searchaccount()
    {
        system("cls");

        cout << "\n\n";

        cout << "\t\t\t\t\t\t\t\t\t\t";

        cout << "\n";

        cout << "\t\t\t\t\t\t\t\t\t\t"
             << "       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~      " << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t"
             << "       |    BANK MANAGEMENT SYSTEM    |     " << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t"
             << "       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~      " << endl;

        cout << "\n";

        cout << "\t\t\t\t\t\t\t\t\t\t"
             << "                                              " << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t "
             << "              Search by Id     " << endl;

        cout << "\t\t\t\t\t\t\t\t\t\t"
             << "                                              " << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t"
             << "                                              " << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t";
        for (int i = 0; i <= 47; i++)
            cout << "-";
        cout << "\n";
        string id1;
        cout << "\t\t\t\t\t      ID  : ";
        cin >> id1;

        ll ob;
        ob.search(id1);
    }
    void displayaccount()
    {
        system("cls");

        cout << "\n\n";

        cout << "\t\t\t\t\t\t\t\t\t\t";

        cout << "\n";

        cout << "\t\t\t\t\t\t\t\t\t\t"
             << "       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~      " << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t"
             << "       |    BANK MANAGEMENT SYSTEM    |     " << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t"
             << "       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~      " << endl;

        cout << "\n";

        cout << "\t\t\t\t\t\t\t\t\t\t"
             << "                                              " << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t "
             << "              All Accounts     " << endl;

        cout << "\t\t\t\t\t\t\t\t\t\t"
             << "                                              " << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t"
             << "                                              " << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t";
        for (int i = 0; i <= 47; i++)
            cout << "-";
        cout << "\n";
        ll ob;
        ob.display();
    }
};
class user : public Bank
{
    string id;

public:
    int usermenu()
    {
        system("color A0");
        int c;
        do
        {
            system("cls");
            cout << "\n\n";

            cout << "\t\t\t\t\t\t\t\t\t\t";
            for (int i = 0; i <= 33; i++)
                cout << load;
            cout << "\n";
            cout << "\t\t\t\t\t\t\t\t\t\t" << load << "                                " << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t" << load << "                                " << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t" << load << "       ~~~~~~~~~~~~~~~~~~~      " << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t" << load << "       |   User Account  |      " << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t" << load << "       ~~~~~~~~~~~~~~~~~~~      " << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t" << load << "                                " << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t" << load << "    [1]  :  Create account      " << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t" << load << "    [2]  :  Login account       " << load << endl;

            cout << "\t\t\t\t\t\t\t\t\t\t" << load << "________________________________" << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t" << load << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t" << load << "       Back  (<-Backspace)      " << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t" << load << "________________________________" << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t";
            for (int i = 0; i <= 33; i++)
                cout << load;
            cout << "\n";
            c = getch();
        } while (c != '1' && c != '2' && c != 8);
        return c;
    }
    void createaccount()
    {
        system("cls");

        cout << "\n\n";

        cout << "\t\t\t\t\t\t\t\t\t\t";

        cout << "\n";

        cout << "\t\t\t\t\t\t\t\t\t\t"
             << "       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~      " << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t"
             << "       |    BANK MANAGEMENT SYSTEM    |     " << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t"
             << "       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~      " << endl;

        cout << "\n";

        cout << "\t\t\t\t\t\t\t\t\t\t"
             << "                                              " << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t"
             << "       Please enter the following details     " << endl;

        cout << "\t\t\t\t\t\t\t\t\t\t"
             << "           for creating an account            " << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t"
             << "                                              " << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t"
             << "                                              " << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t";
        for (int i = 0; i <= 47; i++)
            cout << "-";
        cout << "\n";
        string name, address, pin, phone;
        int length, an;
        char password;
        
        cout << "\n\t\t\t\t\t  User name:   ";
        cin.ignore();
        getline(cin, name);
        cout << name;
  stringstream ss; 
        cout << "\n\t\t\t\t\t  User id:   ";
        srand(time(0));
        int d = (rand() % 1000) + 1;
        ss<<d;
        ss>>id;
        cout<<id;


        cout << "\n\t\t\t\t\t  Address:   ";
        cin.ignore();
        getline(cin, address);

        length = 0;
        password = 0;

        cout << "\n\t\t\t\t\t  PIN:    ";
        while (length != 4) // ascii code of enter. this will turminate on enter
        {
            if (password >= 48 && password <= 57) // take value only in numeric form
            {
                pin.push_back(password);
                cout << "*";
                length++;
            }
            password = getch(); // take value char by char
        }

        length = 0;
        password = 0;
        cout << "\n\n\t\t\t\t\t  Mobile:   ";
        while (length != 10) // ascii code of enter. this will turminate on enter
        {
            if (password >= 48 && password <= 57) // take value only in numeric form
            {
                phone.push_back(password);
                cout << password;
                length++;
            }
            password = getch(); // take value char by char
        }

        ifstream r("count.txt");

        int i = 0;
        if (r)
        {
            r >> i;
            ofstream s("count.txt");
            i = i + 6;
            s << i;
        }
        else
        {
            ofstream s("count.txt");
            i = 0;
            i = i + 6;
            s << i;
        }
        r.close();
        ll Ob;
        Ob.Create_New_Account(name, id, address, pin, phone, 5000);

        cout << "\n\t\t\t\t\t";
        for (int i = 0; i <= 31; i++)
            cout << "-";
        cout << "\n\n";

        cout << "\t\t\t\t\t"
             << "   Account Has Been Created   " << endl;

        cout << "\t\t\t\t\t";

        for (int i = 0; i <= 31; i++)
            cout << "-";
        cout << "\n\n";
    }
    bool loginaccount()
    {
        bool log = false;
        system("color 0A");
        int length = 0;
        char password = 0;
        string pin;

        string check_id, check_pin, data, data1, data2, data3, data4;
        int index, index1, index2, position, no, g;
        int W, D;
        cout << "\n\n\n\n\n\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t";
        for (int j = 0; j <= 31; j++)
            cout << load;
        cout << "\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t" << load << "                              " << load << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t\t" << load << "  BANKING MANAGEMENT SYSTEM   " << load << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t\t" << load << "                              " << load << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t\t";
        for (int j = 0; j <= 31; j++)
            cout << load;
        cout << "\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t" << load << "                              " << load << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t\t" << load << "                              " << load << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t\t" << load << "      ~~~~~~~~~~~~~~~~~~~     " << load << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t\t" << load << "      |  Login Account  |     " << load << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t\t" << load << "      ~~~~~~~~~~~~~~~~~~~     " << load << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t\t" << load << "                              " << load << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t\t         ID  : ";
        cin >> id;
        cout << "\t\t\t\t\t\t\t\t\t\t\t         PIN : ";
        while (length != 4) // ascii code of enter. this will turminate on enter
        {
            if (password >= 48 && password <= 57) // take value only in numeric form
            {
                pin.push_back(password);
                cout << "*";
                length++;
            }
            password = getch(); // take value char by char
        }
        ifstream r("count.txt");
        if (r)
        {
            r >> no;
        }
        else
        {
            cout << "\t\t\t\t\t\t\t\t\t\t"
                 << "                                              " << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t"
                 << "           NO ACCOUNTS TO DISPLAY!      " << endl;
            for (int i = 0; i < 99; i++)
            {
                Sleep(1);
            }
            return false;
        }

        r.close();
        ifstream w("user.txt");
        char o = 3;
        for (int i = 0; i < no; i++)
        {
            cout << endl;
            w >> data1;
            w >> check_id;

            w >> data2;
            w >> check_pin;

            w >> data3;
            w >> data4;
            if (check_id == id && check_pin == pin)
            {

                cout << "\t\t\t\t\t\t\t\t\t\t\t";
                for (int j = 0; j <= 31; j++)
                    cout << load;
                cout << "\n";
                cout << "\t\t\t\t\t\t\t\t\t\t\t" << load << "                              " << load << endl;
                cout << "\t\t\t\t\t\t\t\t\t\t\t       WELCOME  " << data1 << " " << o << endl;
                cout << "\t\t\t\t\t\t\t\t\t\t\t" << load << "                              " << load << endl;
                position = i;
                cout << "\t\t\t\t\t\t\t\t\t\t\t";
                for (int j = 0; j <= 31; j++)
                    cout << load;
                cout << "\n\n";
                getch();
                log = true;
            }

            i = i + 5;
        }
        w.close();
        if (log == false)
        {
            cout << "\t\t\t\t\t\t\t\t\t\t\t";
            for (int j = 0; j <= 31; j++)
                cout << load;
            cout << "\n";
            cout << "\t\t\t\t\t\t\t\t\t\t\t" << load << "                              " << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t\t" << load << "     Incorrect Password       " << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t\t" << load << "                              " << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t\t";
            for (int j = 0; j <= 31; j++)
                cout << load;
            cout << "\n\n";
            getch();
        }
        return log;
    }
    int loginmenu()
    {
        system("color D0");
        int c;
        do
        {
            system("cls");
            cout << "\n\n";

            cout << "\t\t\t\t\t\t\t\t\t\t";
            for (int i = 0; i <= 33; i++)
                cout << load;
            cout << "\n";
            cout << "\t\t\t\t\t\t\t\t\t\t" << load << "                                " << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t" << load << "                                " << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t" << load << "       ~~~~~~~~~~~~~~~~~~~      " << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t" << load << "       |   User Account  |      " << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t" << load << "       ~~~~~~~~~~~~~~~~~~~      " << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t" << load << "                                " << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t" << load << "    [1]  :  Withdraw money      " << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t" << load << "    [2]  :  Deposit money       " << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t" << load << "    [3]  :  Close account       " << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t" << load << "    [4]  :  Loan                " << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t" << load << "________________________________" << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t" << load << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t" << load << "       Back  (<-Backspace)      " << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t" << load << "________________________________" << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t";
            for (int i = 0; i <= 33; i++)
                cout << load;
            cout << "\n";
            c = getch();
        } while (c != '1' && c != '2' && c != '3' && c != '4' && c != 8);
        return c;
    }
    void withdraw()
    {
        int g;
        int amount;

        do
        {
            system("cls");
            cout << "\n\n\n\n\n\n";
            cout << "\t\t\t\t\t\t\t\t\t\t\t";

            for (int j = 0; j <= 31; j++)
                cout << load;
            cout << "\n";
            cout << "\t\t\t\t\t\t\t\t\t\t\t" << load << "                              " << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t\t" << load << "  BANKING MANAGEMENT SYSTEM   " << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t\t" << load << "                              " << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t\t";
            for (int j = 0; j <= 31; j++)
                cout << load;
            cout << "\n";
            cout << "\t\t\t\t\t\t\t\t\t\t\t" << load << "                              " << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t\t" << load << "                              " << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t\t" << load << "      ~~~~~~~~~~~~~~~~~~~     " << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t\t" << load << "      |  Withdraw money |     " << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t\t" << load << "      ~~~~~~~~~~~~~~~~~~~     " << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t\t" << load << "                              " << load << endl;

            cout << "\t\t\t\t\t         Amount  : ";
            cin >> amount;
            if (amount <= 0)
            {
                cout << "\n\t\t\t\t\t";
                for (int i = 0; i <= 31; i++)
                    cout << load;
                cout << "\n";
                cout << "\t\t\t\t\t" << load << "                              " << load << endl;
                cout << "\t\t\t\t\t" << load << "  Please Enter Valid Range    " << load << endl;
                cout << "\t\t\t\t\t" << load << "                              " << load << endl;
                cout << "\t\t\t\t\t";
                for (int i = 0; i <= 31; i++)
                    cout << load;
                cout << "\n";
                getch();
            }

        } while (amount <= 0);
        cout << "\t\t\t\t\t" << load << "                              " << load << endl;
        cout << "\t\t\t\t\t" << load << "       Yes : ('Y' OR 'y')     " << load << endl;
        cout << "\t\t\t\t\t" << load << "        NO : ('N' OR 'n')     " << load << endl;
        cout << "\t\t\t\t\t" << load << "                              " << load << endl;
        cout << "\t\t\t\t\t";
        for (int j = 0; j <= 31; j++)
            cout << load;
        cout << "\n";
        do
        {
            g = getch();
        } while (g != 'Y' && g != 'y' && g != 'N' && g != 'n');
        system("cls");
        if (g == 'Y' || g == 'y')
        {
            ll Ob;
            Ob.Withdraw_Amount(id, amount);
        }
    }

    void deposit()
    {
        int g;
        int amount;

        do
        {
            system("cls");
            cout << "\n\n\n\n\n\n";
            cout << "\t\t\t\t\t\t\t\t\t\t\t";

            for (int j = 0; j <= 31; j++)
                cout << load;
            cout << "\n";
            cout << "\t\t\t\t\t\t\t\t\t\t\t" << load << "                              " << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t\t" << load << "  BANKING MANAGEMENT SYSTEM   " << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t\t" << load << "                              " << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t\t";
            for (int j = 0; j <= 31; j++)
                cout << load;
            cout << "\n";
            cout << "\t\t\t\t\t\t\t\t\t\t\t" << load << "                              " << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t\t" << load << "                              " << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t\t" << load << "      ~~~~~~~~~~~~~~~~~~~     " << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t\t" << load << "      |  Deposit money  |     " << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t\t" << load << "      ~~~~~~~~~~~~~~~~~~~     " << load << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t\t" << load << "                              " << load << endl;

            cout << "\t\t\t\t\t         Amount  : ";
            cin >> amount;
            if (amount <= 0)
            {
                cout << "\n\t\t\t\t\t";
                for (int i = 0; i <= 31; i++)
                    cout << load;
                cout << "\n";
                cout << "\t\t\t\t\t" << load << "                              " << load << endl;
                cout << "\t\t\t\t\t" << load << "  Please Enter Valid Range    " << load << endl;
                cout << "\t\t\t\t\t" << load << "                              " << load << endl;
                cout << "\t\t\t\t\t";
                for (int i = 0; i <= 31; i++)
                    cout << load;
                cout << "\n";
                getch();
            }

        } while (amount <= 0);
        cout << "\t\t\t\t\t" << load << "                              " << load << endl;
        cout << "\t\t\t\t\t" << load << "       Yes : ('Y' OR 'y')     " << load << endl;
        cout << "\t\t\t\t\t" << load << "        NO : ('N' OR 'n')     " << load << endl;
        cout << "\t\t\t\t\t" << load << "                              " << load << endl;
        cout << "\t\t\t\t\t";
        for (int j = 0; j <= 31; j++)
            cout << load;
        cout << "\n";
        do
        {
            g = getch();
        } while (g != 'Y' && g != 'y' && g != 'N' && g != 'n');
        system("cls");
        if (g == 'Y' || g == 'y')
        {
            ll Ob;
            Ob.Deposit_Amount(id, amount);
        }
    }
    void close()
    {
        cout << "close";
        ll Ob;
        Ob.close_account(id);
    }
    void loan()
    {
        double loan_amount, interest_rate, number_of_years, total_amount, monthly_amount;
        cout << endl;
        interest_rate=9;
 cout << "\t\t\t\t\t\t\t\t\t\t"
             << "interest rate: "<<interest_rate<<"%"<<endl;
        cout << "\t\t\t\t\t\t\t\t\t\t"
             << "Enter the loan amount: ";
        cin >> loan_amount;
        cout << endl;
       
       
        cout << "\t\t\t\t\t\t\t\t\t\t"
             << "The number of years: ";
        cin >> number_of_years;
        cout << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t";
        total_amount = (number_of_years * loan_amount) + (number_of_years * loan_amount * (interest_rate / 100.00));
        monthly_amount = total_amount / (number_of_years * 12);
        for (int i = 0; i <= 47; i++)
            cout << "-";
        cout << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t"
             << "Total amount to be paid: " << total_amount << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t"
             << "Total interest: " << total_amount - (number_of_years * loan_amount) << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t"
             << "Monthly amount to be paid: " << monthly_amount << endl;
    }
};

int main()
{
    Bank *b[3];
    basefun b1;
    admin a1;
    user u1;
    b[0] = &b1;
    b[1] = &a1;
    b[2] = &u1;
    b[0]->loading(" WELCOME TO BANK MANAGEMENT SYSTEM");
    while (true)
    {
        system("color 3F");
        system("cls");
        int choice = b[0]->mainmenu();
        if (choice == '1')
        {
            bool admin;
            int admin_option;

            do
            {

                system("cls");
                admin = b[1]->adminlogin();
            } while (admin == false);
            if (admin == true)
                do
                {
                    admin_option = b[1]->adminmenu();
                    if (admin_option == '1')
                    {
                        b[1]->searchaccount();

                        getch();
                    }
                    else if (admin_option == '2')
                    {
                        b[1]->displayaccount();
                        getch();
                    }

                } while (admin_option != 8);
            admin_option = 0;
        }

        else if (choice == '2')
        {
            int user_option;
            do
            {
                user_option = b[2]->usermenu();
                if (user_option == '1')
                {
                    b[2]->createaccount();

                    getch();
                }
                else if (user_option == '2')
                {
                    bool user;
                    int user_option1;
                    do
                    {

                        system("cls");
                        user = b[2]->loginaccount();
                    } while (user == false);
                    if (user == true)
                        do
                        {
                            user_option1 = b[2]->loginmenu();
                            if (user_option1 == '1')
                            {
                                b[2]->withdraw();

                                getch();
                            }
                            else if (user_option1 == '2')
                            {
                                b[2]->deposit();
                                getch();
                            }
                            else if (user_option1 == '3')
                            {
                                b[2]->close();
                                getch();
                            }
                            else if (user_option1 == '4')
                            {
                                b[2]->loan();
                                getch();
                            }

                        } while (user_option1 != 8);
                    user_option1 = 0;
                }

            } while (user_option != 8);
            user_option = 0;
        }
        else if (choice == 27)
            exit(0);
    }
}