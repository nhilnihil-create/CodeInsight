#include<bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  int A=S.at(0)-'0';
  int B=S.at(1)-'0';
  int C=S.at(2)-'0';
  int D=S.at(3)-'0';
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
  else{
    cout << A << "+" << B << "+" << C << "+" << D << "=7" << endl;
  }
}
  
