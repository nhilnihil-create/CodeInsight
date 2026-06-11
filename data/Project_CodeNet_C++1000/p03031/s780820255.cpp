#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> p(m);
  vector<vector<int>> s(m);
  for (int i = 0; i < m; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int ss;
      cin >> ss;
      ss--;
      s[i].emplace_back(ss);
    }
  }
  for (int i = 0; i < m; i++) {
    cin >> p[i];
  }
  int ans = 0;
  for (int bit = 0; bit < (1 << n); bit++) {
    // cerr << bit << endl;
    bool ok = 1;
    for (int i = 0; i < m; i++) {
      int on = 0;
      for (const auto& e : s[i]) {
        if (bit & (1 << e)) on++;
      }
      if ((on % 2) ^ p[i]) {
        ok = 0;
        break;
      }
      // cerr << on << endl;
    }
    if (ok) ans++;
  }
  cout << ans << '\n';
  return 0;
}