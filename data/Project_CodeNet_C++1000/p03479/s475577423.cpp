// https://atcoder.jp/contests/abc083/tasks/arc088_a

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#define DUMP(a, n) REP(_i, n) printf("%d%c", a[_i], _i + 1 == n ? '\n' : ' ')
#define DUMP2D(a, n, m) REP(_i, n) REP(_j, m) printf("%d%c", a[_i][_j], _j + 1 == m ? '\n' : ' '); puts("")

const ll Y_MAX = 1e18;

ll X, Y;

void solve() {
  int ans = 1;
  while (true) {
    X *= 2;
    if (X > Y) break;
    ans++;
  }
  printf("%d\n", ans);
}

void input() {
  scanf("%lld%lld", &X, &Y);
}

int main() {
  input();
  solve();
  return 0;
}
