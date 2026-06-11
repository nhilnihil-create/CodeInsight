
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
typedef long long ll;

int n;
ll X;
ll xs[200000+10];
ll cs[200000+10];

inline ll calc(ll k, int x) {
  return (k+1)*(k+1)*x;
}

int main(void) {
  cin >> n >> X;
  REP(i, n) {
    cin >> xs[i];
    cs[i+1] = cs[i] + xs[i];
  }
  ll res = 7000000000000000000LL;
  for(int i = 1; i <= (n+1)/2; ++i) {
    ll cur = 5LL*cs[n] + X*i;
    bool over = false;
    for(int i2 = n-i*2; i2 >= 0; i2 -= i) {
      ll tmp = cur + 2*cs[i2];
      if(tmp < 0) {
        over = true;
        // cerr << "over!" << endl;
        break;
      }
      cur = tmp;
    }
    // cerr << ">> " << i << " " << cur << endl;
    if(!over) {
      res = min(res, cur);
    }
  }

  cout << res + (X*n) << endl;
  
  return 0;
}
