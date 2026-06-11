// https://atcoder.jp/contests/abc126/tasks/abc126_f

#include <bits/stdc++.h>

using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#define DUMP(a, n) REP(_i, n) printf("%d%c", a[_i], _i + 1 == n ? '\n' : ' ')
#define DUMP2D(a, n, m) REP(_i, n) REP(_j, m) printf("%d%c", a[_i][_j], _j + 1 == m ? '\n' : ' '); puts("")

const int M_MAX = 17;
const int K_MAX = 1e9;

int M, K;

void solve() {
  if (K >> M) {
    puts("-1");
    return;
  }

  if (M == 1) {
    if (K == 0) {
      puts("0 0 1 1");
    } else {
      puts("-1");
    }
    return;
  }

  REP(i, 1 << M) if (i != K) printf("%d ", i);
  printf("%d ", K);
  for (int i = (1 << M) - 1; i >=0; i --) if (i != K) printf("%d ", i);
  printf("%d\n", K);
}

void input() {
  scanf("%d%d", &M, &K);
}

int main() {
  input();
  solve();
  return 0;
}
