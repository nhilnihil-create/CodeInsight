#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for (int i = (a); i <= (b); ++ i)
#define rrp(i,a,b) for (int i = (a); i >= (b); -- i)
#define gc() getchar()
#define fir first
#define sec second
typedef pair<int,int> pii;
typedef long double db;
typedef long long ll;
template <typename tp>
inline void read(tp& x) {
  x = 0; char tmp; bool key = 0;
  for (tmp = gc(); !isdigit(tmp); tmp = gc())
    key = (tmp == '-');
  for (; isdigit(tmp); tmp = gc())
    x = (x << 3) + (x << 1) + (tmp ^ '0');
  if (key) x = -x;
}
template <typename tp>
inline void ckmn(tp& x,tp y) {
  x = x < y ? x : y;
}
template <typename tp>
inline void ckmx(tp& x,tp y) {
  x = x < y ? y : x;
}

const ll INF = 1ll << 60;
const int N = 5010;
int n, A, B, per[N], mx[N], num[N], pla[N];
ll dp[N][N], ans;
int main() {
  read(n), read(A), read(B);
  rep (i, 1, n) read(per[i]), pla[per[i]] = i;
  memset(dp, 0x3f, sizeof dp);
  dp[n][n] = 0;
  ans = INF;
  rrp (i, n, 1) {
    rep (j, 1, n) {
      num[j] = 0;
      mx[j] = 0;
      if (per[j] <= i) num[j] = 1, mx[j] = per[j];
    }
    rep (j, 2, n) mx[j] = max(mx[j], mx[j-1]);
    rep (j, 2, n) num[j] += num[j-1];
    rep (j, 1, n) {
      int p = pla[mx[j]];
      if (!p) {
	ckmn(ans, dp[i][j]);
	continue;
      }
      if (mx[j] < i) ckmn(dp[i-1][j], dp[i][j]);
      ckmn(dp[i-1][j], dp[i][j] + A);
      ckmn(dp[i-1][p-1], dp[i][j] + 1ll * B * (num[j] - num[p]));
    }
  }
  rep (i, 0, n) ckmn(ans, dp[i][0]), ckmn(ans, dp[0][i]);
  cout << ans << endl;
  return 0;
}
