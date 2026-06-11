// https://atcoder.jp/contests/abc092/tasks/arc093_a

#include <bits/stdc++.h>

using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#define DUMP(a, n) REP(_i, n) printf("%d%c", a[_i], _i + 1 == n ? '\n' : ' ')
#define DUMP2D(a, n, m) REP(_i, n) REP(_j, m) printf("%d%c", a[_i][_j], _j + 1 == m ? '\n' : ' '); puts("")

const int N_MAX = 1e5;
const int A_I_MAX = 5000;

int N;
int A[N_MAX + 2];
int d[N_MAX + 1];

void solve() {
  for (int i = N - 1; i >= 0; i--) A[i + 1] = A[i];
  A[0] = 0; A[N + 1] = 0;
  int dist = 0;
  REP(i, N + 1) {
    d[i] = abs(A[i + 1] - A[i]);
    dist += d[i];
  }
  // DUMP(A, N + 2);
  // DUMP(d, N + 1);
  // printf("dist:%d\n", dist);
  REP(i, N) {
    int ans = dist - d[i] - d[i + 1] + abs(A[i + 2] - A[i]);
    printf("%d\n", ans);
  }
}

void input() {
  scanf("%d", &N);
  REP(i, N) scanf("%d", A + i);
}

int main() {
  input();
  solve();
  return 0;
}
