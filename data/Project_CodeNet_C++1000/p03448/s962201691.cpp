#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, x;
  cin >> a >> b >> c >> x;

  int res = 0;
  for (int i = 0; i <= a; ++i) {
    for (int j = 0; j <= b; ++j) {
      int y = x - 500 * i - 100 * j;
      if (0 <= y && y / 50 <= c) {
        res++;
      }
    }
  }

  cout << res << endl;
}
