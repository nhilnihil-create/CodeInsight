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

  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  reverse(ALL(a));

  ll u = 2;
  ll l = 2;
  rep(i, n) {
    if (u < a[i]) {
      cout << -1 << endl;
      return 0;
    }

    ll x = l / a[i] + (l % a[i] == 0 ? 0 : 1); // a[i] の倍数で l 以上となる最小値は a[i] の何倍か？
    if (u < x * a[i]) {
      cout << -1 << endl;
      return 0;
    }
    ll y = (u + a[i] - 1) / a[i] + (u % a[i] == 0 ? 1 : 0);  // a[i] の倍数で初めて u を超えるのは a[i] の何倍か？
    if (y * a[i] - 1 < l) {
      cout << -1 << endl;
      return 0;
    }
    l = x * a[i];
    u = y * a[i] - 1;
//    cerr << a[i] << "  " << l << " " << u << endl;
  }

  cout << l << " " << u << endl;

  return 0;
}
