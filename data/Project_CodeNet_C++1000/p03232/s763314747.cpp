/*  -*- coding: utf-8 -*-
 *
 * b.cc: B: Removing Blocks
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

const int MAX_N = 100000;
const int MOD = 1000000007;

/* typedef */

typedef long long ll;

/* global variables */

int as[MAX_N], rcpsums[MAX_N + 1];

/* subroutines */

inline int powmod(int a, int b) {
  int p = 1;
  while (b) {
    if (b & 1) p = (ll)p * a % MOD;
    a = (ll)a * a % MOD;
    b >>= 1;
  }
  return p;
}

/* main */

int main() {
  int n;
  scanf("%d", &n);

  rcpsums[0] = 1;
  int fn = 1;
  for (int i = 0; i < n; i++) {
    scanf("%d", &as[i]);
    rcpsums[i + 1] = (rcpsums[i] + powmod(i + 2, MOD - 2)) % MOD;
    fn = (ll)fn * (i + 1) % MOD;
  }

  int sum = 0;
  for (int i = 0; i < n; i++) {
    int d = ((ll)rcpsums[i] + rcpsums[n - 1 - i] + (MOD - 1)) % MOD;
    sum = (sum + (ll)d * as[i] % MOD) % MOD;
  }

  printf("%lld\n", (ll)sum * fn % MOD);
  return 0;
}

/*
  In case of n == 3:
  123: 1-3 + 2-3 + 3-3
  132: 1-3 + 2-3 + 2-2
  213: 1-3 + 1-1 + 3-3
  231: 1-3 + 3-3 + 1-1
  312: 1-3 + 1-2 + 2-2
  321: 1-3 + 1-2 + 1-1

  1-3 x 6 -> 1-1 x 6, 2-2 x 6, 3-3 x 6
  1-2 x 2, 2-3 x 2 -> 1-1 x 2, 2-2 x 4, 3-3 x 2
  1-1 x 3, 2-2 x 2, 3-3 x 3

  1-1 x 11, 2-2 x 12, 3-3 x 11
  In case of n == 4:
 */
