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
constexpr long long INFLL = 1LL<<62;
constexpr double eps = (1e-9);

using P = pair<ll, ll>;

int count(const vector<P>& p, const ll& x1, const ll& y1, const ll& x2, const ll& y2) {
  int ans = 0;
  for (auto& d : p) {
    ll x = d.first;
    ll y = d.second;
    if (x1 <= x && x <= x2 && y1 <= y && y <= y2) ans++;
  }
  return ans;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;

  vector<P> p;
  vector<ll> x, y;
  rep(i, n) {
    ll a, b;
    cin >> a >> b;
    p.push_back({a, b});
    x.push_back(a);
    y.push_back(b);
  }

  sort(ALL(x));
  x.erase(unique(x.begin(), x.end()), x.end());
  sort(ALL(y));
  y.erase(unique(y.begin(), y.end()), y.end());

  ll ans = INFLL;
  for (int i = 0; i < n-1; i++) {
    for (int j = i+1; j < n; j++) {
      for (int s = 0; s < n-1; s++) {
        for (int t = s+1; t < n; t++) {
          if (s == t) continue;
          ll x1 = min(x[i], x[j]);
          ll x2 = max(x[i], x[j]);
          ll y1 = min(y[s], y[t]);
          ll y2 = max(y[s], y[t]);
          if (count(p, x1, y1, x2, y2) >= k) {
            chmin(ans, (x2 - x1) * (y2 - y1));
          }
        }
      }
    }
  }

  cout << ans << endl;

  return 0;
}
