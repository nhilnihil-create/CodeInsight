#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int A,B,C,D;
  A=N/1000;
  B=(N-1000*A)/100;
  C=(N-1000*A-100*B)/10;
  D=N-1000*A-100*B-10*C;
  if(A+B+C+D==7){
    cout << A << "+" << B << "+" << C << "+" << D << "=7" << endl;
    return 0;
  }
  if(A+B+C-D==7){
    cout << A << "+" << B << "+" << C << "-" << D << "=7" << endl;
    return 0;
  }
  if(A+B-C+D==7){
    cout << A << "+" << B << "-" << C << "+" << D << "=7" << endl;
    return 0;
  }
  if(A+B-C-D==7){
    cout << A << "+" << B << "-" << C << "-" << D << "=7" << endl;
    return 0;
  }
  if(A-B+C+D==7){
    cout << A << "-" << B << "+" << C << "+" << D << "=7" << endl;
    return 0;
  }
  if(A-B+C-D==7){
    cout << A << "-" << B << "+" << C << "-" << D << "=7" << endl;
    return 0;
  }
  if(A-B-C+D==7){
    cout << A << "-" << B << "-" << C << "+" << D << "=7" << endl;
    return 0;
  }
  if(A-B-C-D==7){
    cout << A << "-" << B << "-" << C << "-" << D << "=7" << endl;
    return 0;
  }
}
