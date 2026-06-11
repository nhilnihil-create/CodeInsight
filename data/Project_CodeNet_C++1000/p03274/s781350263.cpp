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

  ll n, k; cin >> n >> k;
  vector<ll> x(n);
  rep(i, n) cin >> x[i];

  vector<ll> l, r;
  r.push_back(0);
  rep(i, n) {
    if (x[i] < 0) l.push_back(-x[i]);
    if (x[i] > 0) r.push_back(x[i]);
    if (x[i] == 0) k--;
  }
  l.push_back(0);
  reverse(ALL(l));

  ll ans = INFLL;
  for (int i = 0; i <= k; i++) {
    if (i >= r.size()) break;
    if (i == k) {
      chmin(ans, r[i]);
      break;
    }
    if (k-i >= l.size()) continue;
    chmin(ans, r[i] * 2 + l[k-i]);
  }

  for (int i = 0; i <= k; i++) {
    if (i >= l.size()) break;
    if (i == k) {
      chmin(ans, l[i]);
      break;
    }
    if (k-i >= r.size()) continue;
    chmin(ans, l[i] * 2 + r[k-i]);
  }

  cout << ans << endl;

  return 0;
}
