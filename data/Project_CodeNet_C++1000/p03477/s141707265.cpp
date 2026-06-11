#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, d, x, y;
  cin >> a >>  b >> c >> d;
  x = a + b;
  y = c + d;
  if (x > y) {
    cout << "Left" << endl;
  }
  if (x== y) {
    cout << "Balanced" << endl;
  }
  if (x < y) {
    cout << "Right" << endl;
  }
}