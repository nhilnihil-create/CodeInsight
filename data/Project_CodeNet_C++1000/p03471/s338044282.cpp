#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.hpp>
#else
#define debug(...) void()
#endif

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, y;
  cin >> n >> y;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      int c10k = i, c5k = j, c1k = n - i - j;
      if (c1k < 0) continue;
      if (c10k * 10000 + c5k * 5000 + c1k * 1000 == y) {
        cout << i << ' ' << j << ' ' << n - i - j << '\n';
        return 0;
      }
    }
  }
  cout << -1 << ' ' << -1 << ' ' << -1 << '\n';
  return 0;
}