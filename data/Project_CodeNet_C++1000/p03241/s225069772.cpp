#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n, m;
  cin >> n >> m;
  int res = 0;
  for (int i = 1; i * i <= m; i++) {
    if (m % i == 0) {
      int k = m / i;
      if (m / i >= n) res = max(res, i);
      if (m / k >= n) res = max(res, k);
    }
  }
  cout << res << '\n';
  return 0;
}