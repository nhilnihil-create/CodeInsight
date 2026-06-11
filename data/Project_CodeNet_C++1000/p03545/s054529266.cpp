#include <bits/stdc++.h>
using namespace std;

int main() {
  int X, A, B, C, D;
  cin >> X;
  A=X/1000;
  B=(X-A*1000)/100;
  C=(X-A*1000-B*100)/10;
  D=X%10;
  
  if(A+B+C+D==7)cout << A << "+" << B << "+" << C << "+" << D << "=7" << endl;
  else if(A-B+C+D==7)cout << A << "-" << B << "+" << C << "+" << D << "=7" << endl;
  else if(A+B-C+D==7)cout << A << "+" << B << "-" << C << "+" << D << "=7" << endl;
  else if(A+B+C-D==7)cout << A << "+" << B << "+" << C << "-" << D << "=7" << endl;
  else if(A-B-C-D==7)cout << A << "-" << B << "-" << C << "-" << D << "=7" << endl;
  else if(A+B-C-D==7)cout << A << "+" << B << "-" << C << "-" << D << "=7" << endl;
  else if(A-B+C-D==7)cout << A << "-" << B << "+" << C << "-" << D << "=7" << endl;
  else if(A-B-C+D==7)cout << A << "-" << B << "-" << C << "+" << D << "=7" << endl;

}