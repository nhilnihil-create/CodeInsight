#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
using ll = long long;
const int INF = (1<<30)-1;
const long long LINF = (1LL<<62)-1;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
//template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

using P = pair<int, int>;
void chmax(P &a, P b) {
  if (a.first < b.first) {
    a.second = max(a.first, b.second);
    a.first = b.first;
  }
  else
    a.second = max(a.second, b.first);
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(1<<n);
  rep(i, 1<<n) cin >> a[i];
  vector<vector<P>> dp(1<<n, vector<P>(n+1));
  rep(i, 1<<n)
    dp[i][0].first = a[i];
  rep(j, n) {
    rep(i, 1<<n) {
      chmax(dp[i][j+1], dp[i][j]);
      if (i>>j & 1)
        chmax(dp[i][j+1], dp[i^1<<j][j]);
    }
  }
  vector<int> res(1<<n);
  for (int i = 1; i < 1<<n ; i++) {
    res[i] = max(res[i-1], dp[i][n].first+dp[i][n].second);
    cout << res[i] << '\n';
  }
  return 0;
}