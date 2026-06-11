#include <bits/stdc++.h>
#define GET_REP(_1, _2, _3, NAME, ...) NAME
#define rep(...) GET_REP(__VA_ARGS__, irep, _rep)(__VA_ARGS__)
#define rep1(...) GET_REP(__VA_ARGS__, irep1, _rep1)(__VA_ARGS__)
#define _rep(i, n) irep (i, 0, n)
#define _rep1(i, n) irep1(i, 1, n)
#define irep(i, a, n) for (int i = a; i < (int)(n); ++i)
#define irep1(i, a, n) for (int i = a; i <= (int)(n); ++i)
#define rrep(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define rrep1(i, n) for (int i = (int)(n); i >= 1; --i)
#define allrep(X, x) for (auto &&X : x)
#define all(x) begin(x), end(x)
#ifdef LOCAL
  #include "../../Lib/cout_container.hpp"
  #define debug(x) cout << #x " => " << (x) << endl
#else
  #define debug(x) 0
#endif
using lint = long long;
constexpr int    INF  = 1 << 29;
constexpr lint   INFL = 1LL << 61;
constexpr int    MOD  = (int)1e9 + 7;
constexpr double EPS  = 1e-9;
using namespace std;
namespace { struct INIT { INIT() { cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(15); } } INIT; }

int main(void) {
  int n, m;
  cin >> n >> m;
  vector<int> a(m), b(m);
  rep (i, m) cin >> a[i];
  const vector<int> match{0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
  rep (i, m) b[i] = match[a[i]];
  unordered_map<int, int> num;
  rep (i, m) num[b[i]] = max(num[b[i]], a[i]);
  sort(all(b));
  b.erase(unique(all(b)), b.end());
  const int bs = b.size();
  vector<map<int, int>> dp(n + 1);
  auto comp =
    [&](map<int, int> &x, map<int, int> &y) {
      if (x[0] != y[0]) {
        return x[0] < y[0];
      } else {
        for (auto xitr = x.rbegin(), yitr = y.rbegin(); xitr != x.rend() && yitr != y.rend(); ++xitr, ++yitr) {
          int xf = xitr->first, xs = xitr->second, yf = yitr->first, ys = yitr->second;
          if (xf != yf) {
            return xf < yf;
          } else {
            if (xs != ys) return xs < ys;
          }
        }
        return true;
      }
    };
  dp[0][0] = 0;
  rep (i, n + 1) {
    if (dp[i].empty()) continue;
    rep (j, bs) {
      if (i + b[j] > n) continue;
      auto tmp = dp[i];
      ++tmp[0];
      ++tmp[num[b[j]]];
      if (comp(dp[i + b[j]], tmp)) dp[i + b[j]] = tmp;
    }
  }
  string ans;
  for (auto itr = dp[n].rbegin(); itr != --dp[n].rend(); ++itr) {
    ans += string(itr->second, itr->first + '0');
  }
  cout << ans << endl;
  return 0;
}