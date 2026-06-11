#include <bits/stdc++.h>
using namespace std;

int main () {
  int  a, b, c;
  cin >> a >> b >> c; 
  
  if ((a > b) && (a > c)) cout << a*10 + b + c << endl;
  else if (b > c) cout << a + 10*b + c << endl;
  else cout << a + b + 10*c << endl;
}