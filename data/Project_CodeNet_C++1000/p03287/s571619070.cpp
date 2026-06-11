#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
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

constexpr int INF = 1e9 + 5;
constexpr long long INFLL = 1LL << 62;
constexpr double eps = (1e-9);


int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n, m;
  cin >> n >> m;
  vector<ll> a(n, 0);
  rep(i, n) cin >> a[i];

  vector<ll> cs(n, 0);
  cs[0] = a[0] % m;
  for (int i = 1; i < n; i++) {
    cs[i] = (cs[i-1] + a[i]) % m;
  }

  map<ll, ll> mp;
  for (auto& x : cs) {
    mp[x]++;
  }

  ll ans = 0;
  for (auto& p : mp) {
    if (p.first == 0) ans += p.second;
    if (p.second >= 2) ans += (p.second * (p.second - 1)) / 2LL;
  }

  cout << ans << endl;

  return 0;
}
