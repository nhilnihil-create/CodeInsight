#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  double d, f;
  cin >> a >> b;
  d = (double) ( a + b ) / 2;
  f = (double) (int) d;
  cout << ( f == d ? (int) d : (int) d + 1 ) << endl;
}