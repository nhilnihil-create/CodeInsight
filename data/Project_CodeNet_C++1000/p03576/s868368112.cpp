#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
#define equals(a, b) (fabs((a) - (b)) < EPS)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const ll mod2 = 998244353;
const ll INF = 4e18;
const long double EPS = 1e-10;

int main() {
  int n, K;
  cin >> n >> K;
  vector<pair<int, int>> p(n);
  rep(i, n) cin >> p[i].first >> p[i].second;

  vector<int> x(n), y(n);
  rep(i, n) {
    x[i] = p[i].first;
    y[i] = p[i].second;
  }
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());

  vector<vector<int>> c(n + 1, vector<int>(n + 1, 0));
  rep(i, n) {
    rep(j, n) {
      rep(k, n) {
        if (p[i].first == x[j] && p[i].second == y[k]) {
          c[j + 1][k + 1]++;
        }
      }
    }
  }
  rep(i, n) {
    rep(j, n) {
      c[i + 1][j + 1] += c[i + 1][j] + c[i][j + 1] - c[i][j];
    }
  }

  ll ans = INF;
  rep(i, n) {
    FOR(j, i, n) {
      rep(k, n) {
        FOR(l, k, n) {
          if (c[j + 1][l + 1] - c[i][l + 1] - c[j + 1][k] + c[i][k] >= K) {
            ll rx = max(1, x[j] - x[i]), ry = max(1, y[l] - y[k]);
            ans = min(ans, rx * ry);
          }
        }
      }
    }
  }
  cout << ans << endl;

  






  
  return 0;
}