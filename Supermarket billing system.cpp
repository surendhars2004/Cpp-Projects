#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class shopping {
private:J
    int pcode;
    string pname;
    float price;
    float discount;

public:
    void menu();
    void administration();
    void buyer();
    void add();
    void edit();
    void Delete();
    void receipt();
    void list();
};

void shopping::menu() {
    int choice;
    while (true) {
        cout << "\n\t\t============================================================\n";
        cout << "\t\t                    SHOPPING MAIN MENU                       \n";
        cout << "\t\t============================================================\n";
        cout << "\t\t  1. Administration\n";
        cout << "\t\t  2. Buy Online\n";
        cout << "\t\t  3. Exit\n";
        cout << "\t\t  4. Display Items\n";
        cout << "\n\t\t  Please select an option: ";
        cin >> choice;

        string eMail, passWord;

        switch (choice) {
            case 1:
                cout << "\n\t\t============================================================\n";
                cout << "\t\t                      ADMIN LOGIN                           \n";
                cout << "\t\t============================================================\n";
                cout << "\t\t  Enter Email ID: ";
                cin >> eMail;
                cout << "\t\t  Enter Password: ";
                cin >> passWord;

                if (eMail == "sureyy" && passWord == "sureyy") {
                    cout << "\n\t\t  Login Successful!\n";
                    administration();
                } else {
                    cout << "\n\t\t  Incorrect Login Credentials. Try Again.\n";
                }
                break;

            case 2:
                buyer();
                break;

            case 3:
                cout << "\n\t\t  Thank you for visiting! Exiting the program...\n";
                return;

            case 4:
                list();
                break;

            default:
                cout << "\n\t\t  Invalid Input. Please try again.\n";
        }
    }
}

void shopping::administration() {
    cout << "\n\t\t============================================================\n";
    cout << "\t\t             ADMINISTRATION SECTION                          \n";
    cout << "\t\t============================================================\n";
    while (true) {
        int choice;
        cout << "\n\t\t  1. Add New Product\n";
        cout << "\t\t  2. Modify Product\n";
        cout << "\t\t  3. Delete Product\n";
        cout << "\t\t  4. Go to Main Menu\n";
        cout << "\t\t  5. Exit\n";
        cout << "\t\t  6. Display \n";
        cout << "\n\t\t  Please select an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                add();
                break;
            case 2:
                edit();
                break;
            case 3:
                Delete();
                break;
            case 4:
                menu();
                break;
            case 5:
            	cout << "\n\t\t  Thank you for visiting! Exiting the program...\n";
                exit(0);
            case 6:
            	list();
            	break;
            default:
                cout << "\n\t\t  Invalid Input. Please try again.\n";
        }
    }
}

void shopping::buyer() {
    cout << "\n\t\t============================================================\n";
    cout << "\t\t                   BUYER SECTION                             \n";
    cout << "\t\t============================================================\n";
    while (true) {
        int choice;
        cout << "\n\t\t  1. Buy Product\n";
        cout << "\t\t  2. Go to Main Menu\n";
        cout << "\t\t  3. Exit\n";
        cout << "\n\t\t  Please select an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                receipt();
                break;
            case 2:
                menu();
                break;
            case 3:
            	cout << "\n\t\t  Thank you for visiting! Exiting the program...\n";
                exit(0);
            default:
                cout << "\n\t\t  Invalid Input. Please try again.\n";
        }
    }
}

void shopping::add() {
    int c, token = 0;
    string n;
    float p, d;
    fstream data, temp;

    cout << "\n\t\t============================================================\n";
    cout << "\t\t                  ADD NEW PRODUCT                            \n";
    cout << "\t\t============================================================\n";
    cout << "\t\t  Enter Product Code      : ";
    cin >> pcode;
    cout << "\t\t  Enter Product Name      : ";
    cin >> pname;
    cout << "\t\t  Enter Product Price     : ";
    cin >> price;
    cout << "\t\t  Enter Product Discount  : ";
    cin >> discount;

    data.open("datafile_supermarket.txt", ios::in);
    if (!data) {
        temp.open("datafile_supermarket.txt", ios::out);
        temp << pcode << " " << pname << " " << price << " " << discount << "\n";
        temp.close();
        cout << "\n\t\t  Product added successfully!\n";
    } else {
        data >> c >> n >> p >> d;
        while (!data.eof()) {
            if (c == pcode) {
                cout << "\n\t\t  Product already exists.\n";
                token++;
                break;
            }
            data >> c >> n >> p >> d;
        }
        data.close();

        if (token == 0) {
            data.open("datafile_supermarket.txt", ios::out | ios::app);
            data << pcode << " " << pname << " " << price << " " << discount << "\n";
            data.close();
            cout << "\n\t\t  Product added successfully!\n";
        }
    }
}


void shopping::edit() {
    fstream data, data1;
    int pkey, token = 0;
    string n;
    float p, d;
    
    cout << "\n\t\t============================================================\n";
    cout << "\t\t                  MODIFY PRODUCT                             \n";
    cout << "\t\t============================================================\n";
    cout << "\t\t  Enter Product Code to Modify: ";
    cin >> pkey;

    data.open("datafile_supermarket.txt", ios::in);
    if (!data) {
        cout << "\n\t\t  No items found in the database.\n";
    } else {
        data1.open("temp.txt", ios::out);
        data >> pcode >> pname >> price >> discount;
        while (!data.eof()) {
            if (pkey == pcode) {
                cout << "\n\t\t  Enter New Product Name     : ";
                cin >> n;
                cout << "\t\t  Enter New Product Price    : ";
                cin >> p;
                cout << "\t\t  Enter New Product Discount : ";
                cin >> d;
                data1 << pkey << " " << n << " " << p << " " << d << "\n";
                cout << "\n\t\t  Product modified successfully!\n";
                token++;
            } else {
                data1 << pcode << " " << pname << " " << price << " " << discount << "\n";
            }
            data >> pcode >> pname >> price >> discount;
        }
        data.close();
        data1.close();
        remove("datafile_supermarket.txt");
        rename("temp.txt", "datafile_supermarket.txt");

        if (token == 0) {
            cout << "\n\t\t  Product not found!\n";
        }
    }
}

void shopping::Delete() {
    fstream data, data1;
    int pkey, token = 0;

    cout << "\n\t\t============================================================\n";
    cout << "\t\t                  DELETE PRODUCT                             \n";
    cout << "\t\t============================================================\n";
    cout << "\t\t  Enter Product Code to Delete: ";
    cin >> pkey;

    data.open("datafile_supermarket.txt", ios::in);
    if (!data) {
        cout << "\n\t\t  No items found in the database.\n";
    } else {
        data1.open("temp.txt", ios::out);
        data >> pcode >> pname >> price >> discount;
        while (!data.eof()) {
            if (pcode == pkey) {
                cout << "\n\t\t  Product deleted successfully!\n";
                token++;
            } else {
                data1 << pcode << " " << pname << " " << price << " " << discount << "\n";
            }
            data >> pcode >> pname >> price >> discount;
        }
        data.close();
        data1.close();
        remove("datafile_supermarket.txt");
        rename("temp.txt", "datafile_supermarket.txt");

        if (token == 0) {
            cout << "\n\t\t  Product not found!\n";
        }
    }
}

void shopping::list() {
    fstream data;
    data.open("datafile_supermarket.txt", ios::in);
    if (!data) {
        cout << "\n\t\t  No items found in the database.\n";
    } else {
        cout << "\n\t\t              *** DISPLAY ITEMS ***                          \n";
        data >> pcode >> pname >> price >> discount;
        
        cout << "\n\t\t------------------------------------------------------------\n";
        cout << "\t\t" << setw(10) << left  << "Code"
             << setw(20) << left  << "Name"
           	 << setw(15) << right << "Price"
           	 << setw(15) << right << "Discount (%)";
        cout << "\n\t\t------------------------------------------------------------\n";
            	 
        while (!data.eof()) {
            cout << "\t\t" << setw(10) << left  << pcode
            	 << setw(20) << left  << pname
            	 << setw(15) << right << price
            	 << setw(15) << right << discount <<endl;
            data >> pcode >> pname >> price >> discount;
        }
        cout << "\t\t------------------------------------------------------------\n";
        data.close();
    }
}

void shopping::receipt(){
	int c=-1,vc=-1, amt, p_amt_with_dis, total=0;
	string choice="y";
	int arrc[100], arrq[100];
	fstream data;
	
	cout << "\n\t\t============================================================\n";
    cout << "\t\t                  RECEIPT SECTION                             \n";
    cout << "\t\t============================================================\n";
    
    data.open("datafile_supermarket.txt", ios::in);
    if (!data) {
        cout << "\n\t\t  No items found in the database.\n";
    }
	else {
		data.close();
	    list();
    	cout << "\n\t\t\t\t Please Place the Order";
    	while(choice == "y" || choice == "Y"){
    		c++;
	    	cout << "\n\t\t\t\t Enter the product code : ";
    		cin >> arrc[c];
    		cout << "\n\t\t\t\t Enter Quantity         : ";
	    	cin >> arrq[c];
    		cout << "\n\t\t\t\t Want to Buy more product ? press 'y' for yes 'n' for no : ";
    		cin >> choice;
		} 
		cout << "\n\t\t-------------------------------------------------------------";
		cout <<"\n\t\t"
			 << setw(7) << left << "Code"
			 << setw(12) << left << "Name"
			 << setw(10) << right << "Price"
			 << setw(7) << right << "Qty"
			 << setw(7) << right << "amt "
			 << setw(17) << right << "Discount applied" <<endl;
		cout << "\t\t-------------------------------------------------------------";
			 
		data.open("datafile_supermarket.txt", ios::in);

			 
		for(int i=0; i<=c; i++){
			data.seekg(0,ios::beg);
			data >> pcode >> pname >> price >> discount; 
			while(!data.eof()){
				
				if(pcode==arrc[i]){
					
					amt=price*arrq[i];
					p_amt_with_dis = amt - (amt * discount / 100);
                    total += p_amt_with_dis;
					cout <<"\n\t\t"
					     << setw(7) << left << pcode
						 << setw(12) << left << pname
						 << setw(10) << right << price
						 << setw(7) << right << arrq[i]
						 << setw(7) << right << amt
						 << setw(17) << right << p_amt_with_dis <<endl; 
						 break;
				}
				data >> pcode >> pname >> price >> discount; 
			}
			
		}
		data.close(); 
		cout << "\t\t-------------------------------------------------------------"; 
		cout<<"\n\t\t Total Amount : " << total;
		cout << "\n\t\t Make the Payment via Cash, Card, Paytm, PhonePay, Gpay" <<endl;
		exit(0);				
	}	
}

int main() {
    shopping shop;
    shop.menu();
    return 0;
}

