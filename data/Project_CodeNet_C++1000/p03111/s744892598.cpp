// 2020-09-03 00:24:50
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
int n, a, b, c, l[8], ans;
void dfs(int i, int j, int x, int y, int z) {
  if (i == n) {
    if (x > 0 && y > 0 && z > 0) {
      chmin(ans, abs(a - x) + abs(b - y) + abs(c - z) + j - 30);
    }
    return;
  }
  dfs(i + 1, j, x, y, z);
  dfs(i + 1, j + 10, x + l[i], y, z);
  dfs(i + 1, j + 10, x, y + l[i], z);
  dfs(i + 1, j + 10, x, y, z + l[i]);
}
void answer() {
  cin >> n >> a >> b >> c;
  rep(i, n) cin >> l[i];
  ans = inf;
  dfs(0, 0, 0, 0, 0);
  cout << ans << '\n';
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}