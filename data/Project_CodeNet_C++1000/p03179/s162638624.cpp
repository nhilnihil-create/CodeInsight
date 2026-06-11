// https://atcoder.jp/contests/dp/tasks/dp_t

#include <bits/stdc++.h>

using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#define DUMP(a, n) REP(i, n) printf("%d%c", a[i], i + 1 == n ? '\n' : ' ')
#define DUMP2D(a, n, m) REP(i, n) REP(j, m) printf("%d%c", a[i][j], j + 1 == m ? '\n' : ' '); puts("")

const int N_MAX = 3000;
const int MOD = 1e9+7;

int N;
char s[N_MAX];

int dp0[N_MAX];
int dp1[N_MAX];
int acc[N_MAX + 1];

void solve() {
  auto cur = dp0;
  auto nxt = dp1;
  fill(cur, cur + N, 1);
  REP(k, N - 1) {
    int l = N - 1 - k;
    fill(acc, acc + N + 1, 0);
    FOR(i, 0, l) acc[i + 1] = (acc[i] + cur[i]) % MOD;
    fill(nxt, nxt + N, 0);
    REP(i, l) {
      if (s[k] == '<') {
        nxt[i] = (MOD + acc[i + 1] - acc[0]) % MOD;
      } else {
        nxt[i] = (MOD + acc[l + 1] - acc[i + 1]) % MOD;
      }
    }
    swap(cur, nxt);
  }
  printf("%d\n", cur[0]);
}

void input() {
  scanf("%d", &N);
  scanf("%s", s);
}

int main() {
  input();
  solve();
  return 0;
}
