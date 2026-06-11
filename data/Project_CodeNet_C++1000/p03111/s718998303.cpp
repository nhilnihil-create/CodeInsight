// 2020-09-02 23:55:59
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
const int inf = 1e9;
int n, a[3], l[8], m[8], s[3], ans;
int calc() {
  int res = 0;
  memset(s, 0, sizeof s);
  rep(i, n) if (m[i] < 3) {
    s[m[i]] += l[i];
    res += 10;
  }
  res -= 30;
  sort(s, s + 3, greater<int>());
  if (s[2] == 0) res += inf;
  rep(i, 3) res += abs(a[i] - s[i]);
  return res;
}
void dfs(int i) {
  if (i == n) {
    chmin(ans, calc());
    return;
  }
  rep(j, 4) {
    m[i] = j;
    dfs(i + 1);
  }
}
void answer() {
  cin >> n;
  rep(i, 3) cin >> a[i];
  rep(i, n) cin >> l[i];
  ans = inf;
  dfs(0);
  cout << ans << '\n';
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}