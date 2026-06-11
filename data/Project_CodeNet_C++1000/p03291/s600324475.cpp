// https://atcoder.jp/contests/abc104/tasks/abc104_d

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#define DUMP(a, n) REP(_i, n) printf("%d%c", a[_i], _i + 1 == n ? '\n' : ' ')
#define DUMP2D(a, n, m) REP(_i, n) REP(_j, m) printf("%d%c", a[_i][_j], _j + 1 == m ? '\n' : ' '); puts("")
#define DUMP2DLL(a, n, m) REP(_i, n) REP(_j, m) printf("%lld%c", a[_i][_j], _j + 1 == m ? '\n' : ' '); puts("")

const int S_MAX = 1e5;
const int MOD = 1e9+7;
const int A = 1;
const int AB = 2;

char S[S_MAX + 1];

int N;
ll dp[S_MAX + 1][3];
ll c;

void solve() {
  N = strlen(S);
  c = 1;
  REP(i, N) {
    switch (S[i]) {
      case 'A':
        dp[i + 1][0] = dp[i][0];
        dp[i + 1][A] = (dp[i][A] + c) % MOD;
        dp[i + 1][AB] = dp[i][AB];
        break;
      case 'B':
        dp[i + 1][0] = dp[i][0];
        dp[i + 1][A] = dp[i][A];
        dp[i + 1][AB] = (dp[i][AB] + dp[i][A]) % MOD;
        break;
      case 'C':
        dp[i + 1][0] = (dp[i][0] + dp[i][AB]) % MOD;
        dp[i + 1][A] = dp[i][A];
        dp[i + 1][AB] = dp[i][AB];
        break;
      default:
        dp[i + 1][0] = (dp[i][0] * 3 + dp[i][AB]) % MOD;
        dp[i + 1][A] = (dp[i][A] * 3 + c) % MOD;
        dp[i + 1][AB] = (dp[i][AB] * 3 + dp[i][A]) % MOD;
        c = (c * 3) % MOD;
        break;
    }
  }
  // DUMP2DLL(dp, N + 1, 3);
  printf("%lld\n", dp[N][0]);
}

void input() {
  scanf("%s", S);
}

int main() {
  input();
  solve();
  return 0;
}
