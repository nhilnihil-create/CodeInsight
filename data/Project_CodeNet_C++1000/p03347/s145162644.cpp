#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < n; ++i)
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())
#define FORV(i, v) for (auto i = v.begin(); i != v.end(); i++)
using namespace std;

typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const int INF = 1001001001;
const long long INFL = (1LL<<60);
const double eps = (1e-9);

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);

  rep(i, n) cin >> a[i];
  rep(i, n) {
    if (a[i] > i) {
      cout << -1 << endl;
      return 0;
    }
    if (i > 0 && a[i-1] + 1 < a[i]) {
      cout << -1 << endl;
      return 0;
    }
  }

  int last_idx = -1;
  ll ans = 0;
  for (int i = n-1; i >= 0; i--) {
    if (a[i] == 0) continue;
    if (last_idx == i - a[i]) continue;
    last_idx = i - a[i];
    ans += a[i];
  }

  cout << ans << endl;

  return 0;
}
