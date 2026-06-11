#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a, b, c, x;
  double a1, b1, d;
  cin >> a >> b;
  a1 = a;
  b1 = b;
  c = (a+b)/2;
  d = (a1+b1)/2-c;
  x = c + 2*d;
  cout << x << endl;
}