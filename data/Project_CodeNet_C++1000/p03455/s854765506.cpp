#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A, B;
  cin >> A >> B;
  int C=A%2;
  int D=B%2;
  
  if (C==0||D==0) {
    cout<<"Even"<<endl;
  }
  else {
    cout<<"Odd"<<endl;
  }
  }