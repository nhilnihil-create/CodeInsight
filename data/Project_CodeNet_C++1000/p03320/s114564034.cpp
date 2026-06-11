
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;

typedef long long ll;

inline double calc(ll n) {
  double res = 0;
  while(n > 0) {
    res += n % 10;
    n /= 10;
  }
  return res;
}

int main(void) {
  ll K;
  scanf("%lld", &K);

  set<ll> res;
  REP(i, 9) {
    res.insert(i+1);
  }
  ll t = 10;
  for(int d = 1; d <= 15; ++d, t *= 10) { // 下d桁が9のやつ
    for(ll i = 1; ; ++i) {
      ll v1 = t*i + (t-1);
      ll v2 = t*(i+1) + (t-1);
      // cerr << v1 << " " << v2 << endl;
      if(v1 / calc(v1) > v2 / calc(v2)) {
        break;
      }
      res.insert(v1);
    }
  }

  for(ll v : res) {
    if(K-- > 0) {
      printf("%lld\n", v);
    }
  }
  return 0;
}
