#include <bits/stdc++.h>
using namespace std;

int main() {
  double a, b;
  cin >> a >> b;
  double x = ( a + b ) / 2;
  int c = x;
  int y = (x - c) * 2;
  cout << c + y << endl;
}