// https://atcoder.jp/contests/abc117/tasks/abc117_d

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#define DUMP(a, n) REP(_i, n) printf("%d%c", a[_i], _i + 1 == n ? '\n' : ' ')
#define DUMP2D(a, n, m) REP(_i, n) REP(_j, m) printf("%d%c", a[_i][_j], _j + 1 == m ? '\n' : ' '); puts("")
#define DUMPLL(a, n) REP(_i, n) printf("%lld%c", a[_i], _i + 1 == n ? '\n' : ' ')
#define DUMP2DLL(a, n, m) REP(_i, n) REP(_j, m) printf("%lld%c", a[_i][_j], _j + 1 == m ? '\n' : ' '); puts("")

const int N_MAX = 1e5;
const ll K_MAX = 1e12;
const ll A_I_MAX = 1e12;
const int BIT_LEN = 40;

int N;
ll K;
ll A[N_MAX];

int bs[BIT_LEN];
ll cs[2];
ll us[BIT_LEN + 1];
ll ms[BIT_LEN];
ll ds[BIT_LEN + 1];

void solve() {
  REP(i, BIT_LEN) {
    bs[i] = K >> i & 1;
    cs[0] = cs[1] = 0;
    REP(k, N) {
      if (A[k] >> i & 1) cs[1]++;
      else cs[0]++;
    }
    us[i + 1] = us[i] + (cs[1 - bs[i]] << i);
    ms[i] = cs[1] << i;
    ds[i + 1] = ds[i] + (max(cs[0], cs[1]) << i);
  }

  // printf("bs: "); DUMP(bs, BIT_LEN);
  // printf("us: "); DUMPLL(us, BIT_LEN + 1);
  // printf("ms: "); DUMPLL(ms, BIT_LEN);
  // printf("ds: "); DUMPLL(ds, BIT_LEN + 1);

  ll ans = us[BIT_LEN];
  REP (i, BIT_LEN) {
    if (bs[i]) {
      // printf("i=%d: %lld + %lld + %lld\n", i, us[BIT_LEN] - us[i + 1], ms[i], ds[i]);
      ans = max(ans, us[BIT_LEN] - us[i + 1] + ms[i] + ds[i]);
    }
  }

  printf("%lld\n", ans);
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
