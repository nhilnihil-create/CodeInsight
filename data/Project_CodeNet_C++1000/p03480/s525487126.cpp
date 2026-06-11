// https://atcoder.jp/contests/abc083/tasks/arc088_b

#include <bits/stdc++.h>

using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#define DUMP(a, n) REP(_i, n) printf("%d%c", a[_i], _i + 1 == n ? '\n' : ' ')
#define DUMP2D(a, n, m) REP(_i, n) REP(_j, m) printf("%d%c", a[_i][_j], _j + 1 == m ? '\n' : ' '); puts("")

const int S_MAX = 1e5;

char S[S_MAX + 1];

void solve() {
  int N = strlen(S);
  int M = (N + 1) / 2 - 1;
  int f, t;
  for (f = M; f >= 0 && S[f] == S[M]; f--);
  for (t = M; t < N && S[t] == S[M]; t++);
  // printf("M:%d f:%d t:%d\n", M, f, t);
  int ans = min(N - 1 - f, t);
  printf("%d\n", ans);
}

void input() {
  scanf("%s", S);
}

int main() {
  input();
  solve();
  return 0;
}
