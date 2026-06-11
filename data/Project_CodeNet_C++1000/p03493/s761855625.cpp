#include <bits/stdc++.h>
using namespace std;

int main() {
  int a;
  int b1;
  int b2;
  int c;
  int s;
  cin >> s;
  a = s % 10;
  b1 = ( s % 100 - a ) ;
  b2 = b1 / 10;
  c =  ( s - b1 - a ) / 100;
  int kai;
  kai = a + b2 + c;
  cout << kai << endl;
}