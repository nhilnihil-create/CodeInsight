#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n, y;
  cin >> n >> y;

  int a, b, c;
  a = b = c = -1;
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= n - i; ++j) {
      int k = n - i - j;
      if (10000 * i + 5000 * j + 1000 * k == y) {
        a = i;
        b = j;
        c = k;
        break;
      }
    }
  }

  cout << a << ' ' << b << ' ' << c << '\n';

  return 0;
}