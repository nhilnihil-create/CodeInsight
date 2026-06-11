#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;

int main() {
  int n, m;
  cin >> n >> m;

  vector<set<int>> sl(m);
  int s, k;
  rep(i, m) {
    cin >> k;
    rep(j, k) {
      cin >> s;
      sl[i].insert(s - 1);
    }
  }
  vector<int> p(m);
  rep(i, m) cin >> p[i];

  int ans = 0;
  rep(i, (1 << n)) {
    vector<int> sw(n);
    rep(j, n) if (i >> j & 1) sw[j] = 1;

    bool ok = true;
    rep(j, m) {
      int on = 0;
      for (auto c : sl[j]) {
        if (sw[c] == 1) on++;
      }

      if (on % 2 != p[j]) ok = false;
    }
    if (ok) ans++;
  }
  cout << ans << endl;
}
