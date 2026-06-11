// https://atcoder.jp/contests/abc092/tasks/arc093_b

#include <bits/stdc++.h>

using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#define DUMP(a, n) REP(_i, n) printf("%d%c", a[_i], _i + 1 == n ? '\n' : ' ')
#define DUMP2D(a, n, m) REP(_i, n) REP(_j, m) printf("%d%c", a[_i][_j], _j + 1 == m ? '\n' : ' '); puts("")

const int A_MAX = 500;
const int B_MAX = 500;

int A, B;
int g[80][50];

void solve() {
  fill(g[0], g[40], 1);
  REP(i, A - 1) g[i / 25 * 2][i % 25 * 2] = 0;
  REP(i, B - 1) g[41 + i / 25 * 2][i % 25 * 2] = 1;
  puts("80 50");
  REP(i, 80) {
    REP(j, 50) printf("%c", g[i][j] ? '#' : '.');
    printf("\n");
  }
}

void input() {
  scanf("%d%d", &A, &B);
}

int main() {
  input();
  solve();
  return 0;
}
