// 2020-08-30 19:17:40
// clang-format off
#include<bits/stdc++.h>
#ifdef LOCAL
#include "lib/debug.hpp"
#else
#define debug(...) 1
#endif
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define rep(i, n) REP(i, 0, (n))
#define repc(i, n) REPC(i, 0, (n))
#define REP(i, n, m) for (int i = (int)(n); i < (int)(m); i++)
#define REPC(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define REPCM(i, n, m) for (int i = (int)(n); i >= (int)(m); i--)
using namespace std;
using ll = long long;
using ld = long double;
using pr = pair<ll, ll>;
using vll = vector<ll>;
using vpr = vector<pr>;
using P = pair<int, int>;
template<class T> inline bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } else return false; }
template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }

// clang-format on
vector<P> cb[40], b;
void answer() {
  int n, cz;
  cin >> n >> cz;
  rep(i, n) {
    int x, y, c;
    cin >> x >> y >> c;
    c--;
    cb[c].emplace_back(x, y);
  }
  rep(c, cz) {
    if (cb[c].size() == 0) continue;
    sort(ALL(cb[c]));
    rep(i, cb[c].size() - 1) {
      P& cur = cb[c][i];
      P& nxt = cb[c][i + 1];
      if (cur.second == nxt.first) {
        nxt.first = cur.first;
      } else {
        b.emplace_back(cur.first - 1, cur.second);
      }
    }
    P& last = cb[c].back();
    b.emplace_back(last.first - 1, last.second);
  }
  sort(ALL(b));
  int ans = 0;
  multiset<int> t;
  for (auto p : b) {
    if (t.size() > 0) {
      for (auto it = t.begin(); it != t.end() && p.first >= *it;) {
        t.erase(prev(++it));
      }
    }
    t.insert(p.second);
    chmax(ans, int(t.size()));
  }
  cout << ans << '\n';
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}