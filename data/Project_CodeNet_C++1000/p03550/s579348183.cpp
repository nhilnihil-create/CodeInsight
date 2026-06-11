// https://atcoder.jp/contests/abc078/tasks/arc085_b

#include <bits/stdc++.h>

using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#define DUMP(a, n) REP(_i, n) printf("%d%c", a[_i], _i + 1 == n ? '\n' : ' ')
#define DUMP2D(a, n, m) REP(_i, n) REP(_j, m) printf("%d%c", a[_i][_j], _j + 1 == m ? '\n' : ' '); puts("")

const int N_MAX = 2000;
const int Z_MAX = 1e9;
const int W_MAX = 1e9;
const int A_I_MAX = 1e9;

int N, Z, W;
int a[N_MAX];
int memo[2][N_MAX];

int f2(int sen, int i);

int f(int sen, int i) {
  if (memo[sen][i] < 0) {
    memo[sen][i] = f2(sen, i);
  }
  return memo[sen][i];
}

int f2(int sen, int i) {
  int v = (i > 0 ? a[i - 1] : W);
  int sc = abs(v - a[N - 1]);
  FOR(j, i, N - 2) {
    if (sen) {
      sc = max(sc, f(0, j + 1));
    } else {
      sc = min(sc, f(1, j + 1));
    }
  }
  return sc;
}

void solve() {
  fill(memo[0], memo[2], -1);
  printf("%d\n", f(1, 0));
}

void input() {
  scanf("%d%d%d", &N, &Z, &W);
  REP(i, N) scanf("%d", a + i);
}

int main() {
  input();
  solve();
  return 0;
}
