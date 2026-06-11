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

  int n, k;
  cin >> n >> k;
  vector<ll> v(n);
  rep(i, n) cin >> v[i];

  ll ans = 0;
  for (int m = 0; m <= min(k, n); m++) {        // m: 取り出す回数
    for (int x = 0; x <= m; x++) {              // x: 左から取り出す回数
      vector<ll> a;
      rep(i, x) a.push_back(v[i]);
      rep(i, m-x) a.push_back(v[n-i-1]);
      sort(ALL(a), greater<ll>());
      rep(i, k - m) {                      // 価値が負のものを k-m 回まで捨てる
        if (!a.empty() && a.back() < 0) a.pop_back();
        else break;
      }
      chmax(ans, SUM(a));
    }
  }

  cout << ans << endl;

  return 0;
}
