// https://atcoder.jp/contests/abc108/tasks/arc102_a

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#define DUMP(a, n) REP(_i, n) printf("%d%c", a[_i], _i + 1 == n ? '\n' : ' ')
#define DUMP2D(a, n, m) REP(_i, n) REP(_j, m) printf("%d%c", a[_i][_j], _j + 1 == m ? '\n' : ' '); puts("")

const int N_MAX = 2*1e5;
const int K_MAX = 2*1e5;

int N, K;

void solve() {
  ll m = N / K;
  ll ans = m * m * m;
  if (K % 2 == 0) {
    ll m2 = N / (K / 2) - m;
    ans += m2 * m2 * m2;
  }
  printf("%lld\n", ans);
}

void input() {
  scanf("%d%d", &N, &K);
}

int main() {
  input();
  solve();
  return 0;
}
