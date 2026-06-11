#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < n; ++i)
#define sz(x) int(x.size())
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())
#define FORV(i, v) for (auto i = v.begin(); i != v.end(); i++)
using namespace std;

using ll = long long;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const int INF = 1001001001;
const long long INFLL = LLONG_MAX / 3;
const double eps = (1e-9);

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<ll>> w(n+1, vector<ll>(n+1, 0));  // 2次元累積和

  rep(i, m) {
    int l, r; cin >> l >> r;
    w[l][r]++;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
        w[i][j] += w[i][j-1];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
        w[i][j] += w[i-1][j];
    }
  }

  rep(i, q) {
    int l, r; cin >> l >> r;
    ll ans = w[r][r] - w[l-1][r] - w[r][l-1] + w[l-1][l-1];
    cout << ans << endl;
  }

  return 0;
}
