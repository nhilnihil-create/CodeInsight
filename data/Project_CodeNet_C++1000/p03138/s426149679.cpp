// https://atcoder.jp/contests/abc117/tasks/abc117_d

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#define DUMP(a, n) REP(_i, n) printf("%d%c", a[_i], _i + 1 == n ? '\n' : ' ')
#define DUMP2D(a, n, m) REP(_i, n) REP(_j, m) printf("%d%c", a[_i][_j], _j + 1 == m ? '\n' : ' '); puts("")
#define DUMP2DLL(a, n, m) REP(_i, n) REP(_j, m) printf("%lld%c", a[_i][_j], _j + 1 == m ? '\n' : ' '); puts("")

const int N_MAX = 1e5;
const int K_MAX = 1e12;
const int A_I_MAX = 1e12;
const int BIT_LEN = 40;

int N;
ll K;
ll A[N_MAX];

int bs[BIT_LEN];
int cs[2][BIT_LEN];

ll dp[BIT_LEN + 1][2];

void solve() {
  REP(i, BIT_LEN) bs[i] = K >> i & 1;
  REP(k, N) REP(i, BIT_LEN) cs[1][i] += A[k] >> i & 1;
  reverse(bs, bs + BIT_LEN);
  reverse(cs[1], cs[1] + BIT_LEN);
  REP(i, BIT_LEN) cs[0][i] = N - cs[1][i];


  // printf("bs: "); DUMP(bs, BIT_LEN);
  // printf("cs:\n"); DUMP2D(cs, 2, BIT_LEN);

  fill(dp[0], dp[BIT_LEN+1], -1);
  dp[0][0] = 0;
  REP(i, BIT_LEN) {
    // printf("i:%d\n", i);
    REP(smaller, 2) FOR(j, 0, smaller ? 1 : bs[i]) {
      int smaller2 = smaller || j < bs[i];
      ll add = (1LL << BIT_LEN - 1 - i) * cs[1 - j][i];
      if (dp[i][smaller] >= 0) {
        // printf("  j:%d smaller:%d->%d add:%lld\n", j, smaller, smaller2, add);
        dp[i + 1][smaller2] = max(dp[i + 1][smaller2], dp[i][smaller] + add);
      }
    }
  }

  // DUMP2DLL(dp, BIT_LEN + 1, 2);

  printf("%lld\n", max(dp[BIT_LEN][0], dp[BIT_LEN][1]));
}

void input() {
  scanf("%d%lld", &N, &K);
  REP(i, N) scanf("%lld", A + i);
}

int main() {
  input();
  solve();
  return 0;
}
