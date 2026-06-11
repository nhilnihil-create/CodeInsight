#include <bits/stdc++.h>

#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> d(n);
  rep(i, n) cin >> d.at(i);
  int m;
  cin >> m;
  vector<int> t(m);
  rep(i, m) cin >> t.at(i);
  // 問題案を map<点数, 数量> に詰め替え
  map<int, int> mp;
  rep(i, n) {
    mp[d.at(i)]++;
  }
  // 足りているか確認
  bool ok = true;
  for (int u : t) {
    if (mp[u] > 0) {
      mp[u]--;
    } else {
      ok = false;
      break;
    }
  }
  cout << (ok ? "YES" : "NO") << endl;
  return 0;
}
