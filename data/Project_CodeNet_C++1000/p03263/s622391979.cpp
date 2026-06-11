#include <bits/stdc++.h>

#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const ll INF = 1e9;

int main() {
  ll h, w;
  cin >> h >> w;
  ll a[h][w];
  rep(i, h) rep(j, w) cin >> a[i][j];
  vector<vector<ll>> ans;

  rep(i, h - 1) {
    rep(j, w) if (a[i][j] % 2) {
      a[i + 1][j]++;
      ans.push_back({i, j, i + 1, j});
    }
  }
  rep(i, w - 1) if (a[h - 1][i] % 2) {
    a[h - 1][i + 1]++;
    ans.push_back({h - 1, i, h - 1, i + 1});
  }

  cout << ans.size() << endl;
  rep(i, ans.size()) rep(j, 4) cout << ans[i][j] + 1 << (j == 3 ? "\n" : " ");
  return 0;
}
