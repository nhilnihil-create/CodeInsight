#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, x, y, z;
  cin >> a >> b;
  c = 0;
  for (int i = a; i < b + 1; i++) {
    x = i % 100, y = i / 1000;
    z = x / 10 + (x % 10) * 10;
    
    if (z == y) {
      c += 1;
    }
  }
  cout << c << endl;
}