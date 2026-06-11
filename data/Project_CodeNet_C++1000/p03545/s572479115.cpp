#include <bits/stdc++.h>
using namespace std;

int main() {
  char a,b,c,d;
  cin >> a >> b >> c >> d;
  int A = a-'0';
  int B = b-'0';
  int C = c-'0';
  int D = d-'0';
  if(A+B+C+D == 7){
    cout << A << "+" << B << "+" << C << "+" << D << "=7" << endl;
  }
  else if(A+B+C-D == 7){
    cout << A << "+" << B << "+" << C << "-" << D << "=7" << endl;
  }
  else if(A+B-C+D == 7){
    cout << A << "+" << B << "-" << C << "+" << D << "=7" << endl;
  }
  else if(A-B+C+D == 7){
    cout << A << "-" << B << "+" << C << "+" << D << "=7" << endl;
  }
  else if(A+B-C-D == 7){
    cout << A << "+" << B << "-" << C << "-" << D << "=7" << endl;
  }
  else if(A-B+C-D == 7){
    cout << A << "-" << B << "+" << C << "-" << D << "=7" << endl;
  }
  else if(A-B-C+D == 7){
    cout << A << "-" << B << "-" << C << "+" << D << "=7" << endl;
  }
  else{
    cout << A << "-" << B << "-" << C << "-" << D << "=7" << endl;
  }
}
