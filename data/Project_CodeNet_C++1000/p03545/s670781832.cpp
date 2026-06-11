#include <bits/stdc++.h>
using namespace std;

#define NUM_MAX 100001

int main() {
  int N, A, B, C, D;
  cin >> N;
  
  A=N/1000;
  B=N%1000/100;
  C=N%100/10;
  D=N%10;
  
  if(A+B+C+D==7)
    cout << A <<'+' << B << '+' << C << '+' << D << "=7" << endl;
  else if(A-B+C+D==7)
    cout << A <<'-' << B << '+' << C << '+' << D << "=7" << endl;
  else if(A+B-C+D==7)
    cout << A <<'+' << B << '-' << C << '+' << D << "=7" << endl;
  else if(A-B-C+D==7)
    cout << A <<'-' << B << '-' << C << '+' << D << "=7" << endl;
  else if(A+B+C-D==7)
    cout << A <<'+' << B << '+' << C << '-' << D << "=7" << endl;
  else if(A-B+C-D==7)
    cout << A <<'-' << B << '+' << C << '-' << D << "=7" << endl;
  else if(A+B-C-D==7)
    cout << A <<'+' << B << '-' << C << '-' << D << "=7" << endl;
  else if(A-B-C-D==7)
    cout << A <<'-' << B << '-' << C << '-' << D << "=7" << endl;
}