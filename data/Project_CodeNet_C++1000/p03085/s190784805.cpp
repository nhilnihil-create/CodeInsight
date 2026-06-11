#include <bits/stdc++.h>
using namespace std;

int main() {
  char A,B;
  cin >> A;
  if(A=='A'){
   B='T';
  }
  else if(A=='C'){
   B='G';
  }
  else if(A=='T'){
    B='A';
  }
  else{
    B='C';
  }
  cout << B << endl;
}