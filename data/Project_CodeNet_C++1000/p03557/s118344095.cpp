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
template<class T> inline void dump(vector<T> v) { for (auto& x : v) cerr << x << " "; cerr << endl; }
template<class T> inline void dump(vector<pair<T, T>> v) { for (auto& p : v) cerr << p.first << " " << p.second << endl; }
template<class T> inline void dump(vector<vector<T>> vv) { for (auto& v : vv) {for (auto& x : v) cerr << x << " "; cerr << endl;} }

constexpr int INF = 1e9+5;
constexpr long long INFLL = 1LL<<60;
constexpr double eps = (1e-9);

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];
  rep(i, n) cin >> c[i];
  sort(ALL(a));
  sort(ALL(b));
  sort(ALL(c));

  vector<int> ba(n, 0);  // 各 b[i] について自分より真に小さい a が何個あるか
  vector<int> bc(n, 0);  // 各 b[i] について自分より真に大きい c が何個あるか

  rep(i, n) {
    auto itr = lower_bound(ALL(a), b[i]);
    if (itr == a.begin()) continue;
    int idx = itr - a.begin();
    ba[i] = idx;
  }

  rep(i, n) {
    auto itr = upper_bound(ALL(c), b[i]);
    if (itr == c.end()) break;
    int idx = itr - c.begin();
    bc[i] = n - idx;
  }

  ll ans = 0;

  rep(i, n) {
    ans += ll(ba[i]) * ll(bc[i]);
  }

  cout << ans << endl;

  return 0;
}
