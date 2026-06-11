#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  int64_t s = 1000000000;
  for (int i = 0; i <= max(x, y) * 2; i += 2) {
    int64_t t = i * c + max(0, (x - i / 2)) * a + max(0, (y - i / 2)) * b;
    if (t < s) s = t;
  }
  cout << s << endl;
}