// C - Train Ticket
#include <bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin >> str;
    int A,B,C,D;
    A = int(str.at(0) - '0');
    B = int(str.at(1) - '0');
    C = int(str.at(2) - '0');
    D = int(str.at(3) - '0');

    //cout << A << " " << B << " " << C << " " << D <<  endl;   
    if (A + B + C + D  == 7){
        cout << A << "+" << B << "+" << C << "+" << D << "=7" <<  endl;   
    }else if (A + B + C - D  == 7){
        cout << A << "+" << B << "+" << C << "-" << D << "=7" <<  endl;       
    }else if (A + B - C + D  == 7){
        cout << A << "+" << B << "-" << C << "+" << D << "=7" <<  endl;       
    }else if (A + B - C - D  == 7){
        cout << A << "+" << B << "-" << C << "-" << D << "=7" <<  endl;       
    }else if (A - B + C + D  == 7){
        cout << A << "-" << B << "+" << C << "+" << D << "=7" <<  endl;       
    }else if (A - B + C - D  == 7){
        cout << A << "-" << B << "+" << C << "-" << D << "=7" <<  endl;       
    }else if (A - B - C + D  == 7){
        cout << A << "-" << B << "-" << C << "+" << D << "=7" <<  endl;       
    }else if (A - B - C - D  == 7){
        cout << A << "-" << B << "-" << C << "-" << D << "=7" <<  endl;       
    }else{
      ;
    }
  
    return 0;
}