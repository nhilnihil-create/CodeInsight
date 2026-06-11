#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> s[m];
  rep(i, m) {
    int k;
    cin >> k;
    s[i].resize(k);
    rep(j, k) {
      cin >> s[i][j];
      --s[i][j];
    }
  }
  int p[m];
  rep(i, m) cin >> p[i];

  int ans = 0;
  rep(si, 1 << n) {
    int now = 0;
    rep(i, m) {
      int cnt = 0;
      for (auto j : s[i]) {
        if (si >> j & 1) ++cnt;
      }
      if (cnt % 2 == p[i]) ++now;
    }
    if (now == m) ++ans;
  }
  cout << ans << endl;
  return 0;
}
