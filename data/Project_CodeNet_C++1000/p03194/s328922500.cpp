/*  -*- coding: utf-8 -*-
 *
 * c.cc: C - Product and GCD
 */

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
#include<numeric>
#include<utility>
#include<complex>
#include<functional>

using namespace std;

/* constant */

/* typedef */

typedef long long ll;

/* global variables */

/* subroutines */

ll powll(ll a, ll b) {
  ll p = 1;
  while (b > 0) {
    if (b & 1LL) p *= a;
    a *= a;
    b >>= 1;
  }
  return p;
}

/* main */

int main() {
  ll n, p;
  scanf("%lld%lld", &n, &p);

  if (n == 1) printf("%lld\n", p);
  else if (n >= 40) puts("1");
  else {
    ll gcd = 1;
    for (ll k = 2;; k++) {
      ll e = powll(k, n);
      if (p < e) break;
      if (p % e == 0) gcd = k;
    }
    printf("%lld\n", gcd);
  }

  return 0;
}
