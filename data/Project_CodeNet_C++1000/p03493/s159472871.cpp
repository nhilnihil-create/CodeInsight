#include <bits/stdc++.h>
using namespace std;
 
int main() {
  
  int x, a, b, c;
  cin >> x;
  a = x % 2;
  b = ( x - a ) % 4 / 2;
  c = ( x - a - b ) % 8 / 4;
  cout << a + b + c << endl;
}