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

using ll = int64_t;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const int INF = 1001001001;
const ll INFL = (1LL<<60);
const double eps = (1e-9);

ll solve(const vector<ll>& s, const vector<ll>& t, const ll x) {
  ll ls = s[lower_bound(ALL(s), x) - s.begin() - 1];
  ll us = s[lower_bound(ALL(s), x) - s.begin()];
  ll lt = t[lower_bound(ALL(t), x) - t.begin() - 1];
  ll ut = t[lower_bound(ALL(t), x) - t.begin()];

  ll ans = INFL;
  chmin(ans, x - min(ls, lt));   // 左左
  chmin(ans, max(us, ut) - x);   // 右右
  chmin(ans, 2 * (x-ls) + ut - x);  // 左の神社，右の寺
  chmin(ans, 2 * (x-lt) + us - x);  // 左の寺，右の神社
  chmin(ans, 2 * (ut-x) + x - ls);  // 右の寺，左の神社
  chmin(ans, 2 * (us - x) + x - lt); // 右の神社，左の寺
  return ans;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll a, b, q;
  cin >> a >> b >> q;
  vector<ll> s(a+2);
  vector<ll> t(b+2);
  s[0] = -INFL;
  s[a+1] = INFL;
  t[0] = -INFL;
  t[b+1] = INFL;

  rep(i, a) {
    cin >> s[i+1];
  }
  rep(i, b) {
    cin >> t[i+1];
  }

  rep(i, q) {
    ll x;
    cin >> x;
    cout << solve(s, t, x) << endl;
  }

  return 0;
}
