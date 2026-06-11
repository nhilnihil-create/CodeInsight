#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>
#include <queue>
#include <algorithm>
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;
ll mypow(ll x, ll n) {
  if(n == 0) return 1;
  if(n % 2 == 0) return mypow(x*x%MOD, n/2);
  return mypow(x*x%MOD, n/2) * x % MOD;
}

ll vs[100000+10];

ll inv[100000+10];
ll invsum[100000+10];

int main(void) {
  for(int i = 1; i <= 100000; ++i) {
    inv[i] = mypow(i, MOD-2);
    invsum[i] = invsum[i-1] + inv[i];
  }

  int n;
  scanf("%d", &n);
  REP(i, n) {
    scanf("%lld", &vs[i]);
  }
  ll res = 0;
  REP(i, n) {
    // vs[i]の寄与の期待値は、
    //   (0番目が取り除かれる時にi番目まで繋がってる確率) * vs[i]
    // + (1番目が取り除かれる時にi番目まで繋がってる確率) * vs[i]
    // ...
    // で、取り除かれる時に繋がってる確率は、1/(距離+1)
    ll p = (invsum[i+1] + invsum[n-i] - 1) % MOD;
    res = (res + p * vs[i] % MOD) % MOD;
  }
  REP(i, n) {
    res = res * (i+1) % MOD;
  }
  
  cout << res << endl;
  return 0;
}
