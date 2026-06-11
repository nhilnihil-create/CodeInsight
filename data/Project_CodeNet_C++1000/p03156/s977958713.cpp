#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  int x, y, z;
  x = 0;
  y = 0;
  z = 0;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    if (num <= a) {
      x++;
    } else if (num >= b + 1) {
      z++;
    } else {
      y++;
    }
  }
  if (x <= y) {
    if (x <= z) {
      cout << x << endl;
    } else if (x > z) {
      cout << z << endl;
    }
  } else if (x > y) {
    if (y <= z) {
      cout << y << endl;
    } else if (y > z) {
      cout << z << endl;
    }
  }
}