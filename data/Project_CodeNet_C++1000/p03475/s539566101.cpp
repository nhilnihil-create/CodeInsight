#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
#define int long long

signed main() {
  int n;
  cin >> n;

  vector<int> c(n - 1), s(n - 1), f(n - 1);
  for (int i = 0; i < n - 1; i++) {
    cin >> c[i] >> s[i] >> f[i];
  }

  for (int i = 0; i < n; i++) {
    if(i == n - 1) {
      cout << 0 << '\n';
      break;
    }
    int cur = 0;
    for (int j = i; j < n - 1; j++) {
      if(j == i) {
        cur = cur + s[j] + c[j];
        continue;
      }

      cur = max(cur, s[j]);
      int nxt = (cur + f[j] - 1) / f[j];
      nxt *= f[j];
      cur += (nxt - cur);
      cur += c[j];
    }
    cout << cur << '\n';
  }
}
