#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int x = abs(a - b);
  int y = abs(b - c);
  int z = abs(c - a);
  cout << ((z <= d || x <= d && y <= d) ? "Yes" : "No") << "\n";
}