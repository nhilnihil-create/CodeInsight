#include<bits/stdc++.h>
using namespace std;

int main() {
  int S;
  int A,B,C,D;
  cin >> S;
  D=S%10,S/=10;
  C=S%10,S/=10;
  B=S%10,S/=10;
  A=S%10;
  
  if(A-B-C-D==7){
    cout << A << "-" << B << "-" << C << "-" << D << "=7" << endl;
  }
  else if(A-B-C+D==7){
    cout << A << "-" << B << "-" << C << "+" << D << "=7" << endl;
  }
  else if(A-B+C-D==7){
    cout << A << "-" << B << "+" << C << "-" << D << "=7" << endl;
  }
  else if(A-B+C+D==7){
    cout << A << "-" << B << "+" << C << "+" << D << "=7" << endl;
  }
  else if(A+B-C-D==7){
    cout << A << "+" << B << "-" << C << "-" << D << "=7" << endl;
  }
  else if(A+B-C+D==7){
    cout << A << "+" << B << "-" << C << "+" << D << "=7" << endl;
  }
  else if(A+B+C-D==7){
    cout << A << "+" << B << "+" << C << "-" << D << "=7" << endl;
  }
  else if(A+B+C+D==7){
    cout << A << "+" << B << "+" << C << "+" << D << "=7" << endl;
  }
}