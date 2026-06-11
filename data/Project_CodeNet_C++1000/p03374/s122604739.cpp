
#include <cstdio>
#include <iostream>
#include <algorithm>
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;
typedef long long ll;

struct K {
  ll x, v;
};

K vs[100000+10];

ll cs[500000+10];
int OFFSET = 250000;

int main(void) {
  int N;
  ll C;
  scanf("%d%lld", &N, &C);
  REP(i, N) {
    scanf("%lld%lld", &vs[i].x, &vs[i].v);
  }

  ll res = 0;
  cs[OFFSET] = 0;
  REP(i, N) {
    cs[OFFSET+i+1] = cs[OFFSET+i] - (vs[i].x - (i > 0 ? vs[i-1].x : 0)) + vs[i].v;
    res = max(res, cs[OFFSET+i+1]);
  }
  REP(i, N) {
    cs[OFFSET-i-1] = cs[OFFSET-i] - ((i > 0 ? vs[N-i].x : C) - vs[N-i-1].x) + vs[N-i-1].v;
    res = max(res, cs[OFFSET-i-1]);
  }
  // 時計→反時計
  {
    ll maxi = 0;
    for(int i = N-1; i >= 0; --i) {
      ll cur = cs[OFFSET+i+1] - vs[i].x + maxi;
      res = max(res, cur);
      maxi = max(maxi, cs[OFFSET-N+i]);
    }
  }
  // 反時計→時計
  {
    ll maxi = 0;
    REP(i, N) {
      ll cur = cs[OFFSET-N+i] - (C-vs[i].x) + maxi;
      res = max(res, cur);
      maxi = max(maxi, cs[OFFSET+i+1]);
    }
  }
  cout << res << endl;
  return 0;
}
