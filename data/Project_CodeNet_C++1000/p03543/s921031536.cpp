#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A;
  int a,b,c,d;
  cin >> A;

  a = A / 1000 % 10;
  b = A / 100 % 10;
  c = A / 10 % 10;
  d = A / 1 % 10;

  if ( b == c ){
    if ( a == b ){
      cout << "Yes" << endl;
    } else if ( c == d ){
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  } else {
      cout << "No" << endl;
  }
}