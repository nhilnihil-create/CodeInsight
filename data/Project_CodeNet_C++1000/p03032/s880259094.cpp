#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())
using namespace std;

using ll = long long;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const int INF = 1e9;
const long long INFL = 1LL<<60;


int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, k; cin >> n >> k;
  vector<ll> v(n);
  rep(i, n) cin >> v[i];

  ll ans = 0;

  for (int l = 0; l <= n; l++) {
    for (int r = 0; r <= n-l; r++) {
      if (l + r > k) continue;
      auto itr = v.begin();
      auto ritr = v.rbegin();
      vector<ll> a;

      rep(i, l) {
        a.push_back(*itr);
        itr++;
      }
      rep(i, r) {
        a.push_back(*ritr);
        ritr++;
      }

      sort(ALL(a), greater<ll>());

      rep(i, k - l - r) {
        if (!a.empty() && a.back() < 0) a.pop_back();
      }

      chmax(ans, SUM(a));
    }
  }

  cout << ans << endl;

  return 0;
}
