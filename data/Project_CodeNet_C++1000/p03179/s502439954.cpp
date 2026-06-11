#include <bits/stdc++.h>
using namespace std;

#define f(x, y, z) for (int x = (y), __ = (z); x < __; ++x)
#define _rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define mst(x, a) memset(x, a, sizeof(x))

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9 + 7;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int N;
string s;
const int MAXN = 3010;
int dp[MAXN][MAXN];

void solve() {
  mst(dp, 0);
  dp[1][1] = 1;
  for (int i = 2; i <= N; i++) {
    if (s[i - 2] == '>') {
      for (int j = i; j >= 1; j--) {
        dp[i][j] = (dp[i][j + 1] + dp[i - 1][j]) % MOD;
      }
    } else {
      for (int j = 1; j <= i; j++) {
        dp[i][j] = (dp[i][j - 1] + dp[i - 1][j - 1]) % MOD;
      }
    }
  }

  ll ans = 0;
  for (int i = 1; i <= N; i++) {
    ans = (ans + dp[N][i]) % MOD;
  }
  printf("%lld\n", ans);
}

int main() {
  cin >> N >> s;
  solve();
}
