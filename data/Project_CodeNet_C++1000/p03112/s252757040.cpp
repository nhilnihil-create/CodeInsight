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
constexpr long long INFLL = 1LL << 60;
constexpr double eps = (1e-9);

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int a, b, q;
  cin >> a >> b >> q;
  vector<ll> s(a), t(b);
  rep(i, a) cin >> s[i];
  rep(i, b) cin >> t[i];

  rep(i, q) {
    ll x;
    cin >> x;
    ll ans = INFLL;
    auto its = lower_bound(ALL(s), x);
    ll es;  // 東で一番近い神社
    if (its == s.end()) es = INFLL;
    else es = *its - x;
    ll ws;         // 西で一番近い神社
    if (es == 0) ws = 0;
    else if (its == s.begin()) ws = INFLL;
    else ws = x - s[its - s.begin() - 1];

    auto itt = lower_bound(ALL(t), x);
    ll et;  // 東で一番近い寺
    if (itt == t.end()) et = INFLL;
    else et = *itt - x;
    ll wt;         // 西で一番近い寺
    if (et == 0) wt = 0;
    else if (itt == t.begin()) wt = INFLL;
    else wt = x - t[itt - t.begin() - 1];

    // cerr << ws << " " << es << "  " << wt << " " << ws << endl;

    // w w: 西の s or t の遠い方
    chmin(ans, max(ws, wt));
    // w e: 西にある s or t と東にある s or t
    chmin(ans, ws * 2 + et);
    chmin(ans, wt * 2 + es);
    // e w: 東にある s or t と西にある s or t
    chmin(ans, ws + et * 2);
    chmin(ans, wt + es * 2);
    // e e: 東の s or t の遠い方
    chmin(ans, max(es, et));

    cout << ans << endl;
  }

  return 0;
}
