#include <bits/stdc++.h>
using namespace std;
 
int main() {
  double a,b;
  int x,y,z;
  cin >> a >> b;
  x = (a + b) * 10 / 2;
  y = x % 2;
  z = x/10;
  cout << z+y << endl;
}