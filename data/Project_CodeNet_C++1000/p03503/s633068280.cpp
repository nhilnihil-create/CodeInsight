#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n;
  cin >> n;
  vector<vector<int>> f(n, vector<int>(10)), p(n, vector<int>(11));
  rep(i, n) rep(j, 10) cin >> f[i][j];
  rep(i, n) rep(j, 11) cin >> p[i][j];

  ll ans = -1e9;
  for (int si = 1; si < (1 << 10); si++) {
    vector<int> d(10);
    rep(i, 10) d[i] = (si >> i & 1);

    ll profit = 0;
    rep(i, n) {
      ll c = 0;
      rep(j, 10) if (d[j] == 1 && f[i][j] == 1) c++;
      profit += p[i][c];
    }
    ans = max(ans, profit);
  }
  cout << ans << endl;
  return 0;
}
