// Copyright lzt
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<iostream>
#include<queue>
#include<string>
#include<ctime>
using namespace std;
typedef long long ll;
typedef std::pair<int, int> pii;
typedef long double ld;
typedef unsigned long long ull;
typedef std::pair<long long, long long> pll;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, j, k)  for (register int i = (int)(j); i <= (int)(k); i++)
#define rrep(i, j, k) for (register int i = (int)(j); i >= (int)(k); i--)
#define Debug(...) fprintf(stderr, __VA_ARGS__)

inline ll read() {
  ll x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') {
    x = 10 * x + ch - '0';
    ch = getchar();
  }
  return x * f;
}

void work() {
  int x = read();
  printf("%d\n", (x - 2) * 180);
}

int main() {
  #ifdef LZT
    freopen("in", "r", stdin);
  #endif

  work();

  #ifdef LZT
    Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
  #endif
}
