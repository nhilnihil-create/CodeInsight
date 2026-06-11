#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using int64 = int64_t;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> s(m);
  rep(i, m) {
    int k;
    cin >> k;
    while (k--) {
      int a;
      cin >> a;
      --a;
      s[i].emplace_back(a);
    }
  }
  vector<int> p(m);
  rep(i, m) {
    cin >> p[i];
  }
  int ans = 0;
  rep(bit, 1 << n) {
    vector<bool> on(n, false);
    rep(i, n) {
      if (bit & (1 << i)) on[i] = true;
    }
    bool ok = true;
    rep(i, m) {
      int cnt = 0;
      for (auto&& e : s[i]) {
        if (on[e]) ++cnt;
      }
      if (cnt % 2 != p[i] % 2) {
        ok = false;
        break;
      }
    }
    if (ok) ++ans;
  }
  cout << ans;
  return 0;
}