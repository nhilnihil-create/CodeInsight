#ifdef DBG1
  #define LOCAL
#endif

#ifdef LOCAL
  #define _GLIBCXX_DEBUG
#endif

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>

#ifdef DBG1
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;

bool solve() {
  ll a, b;
  if (scanf("%lld%lld", &a, &b) != 2) { return false; }

  if (a == b) {
    printf("%lld\n", 2 * a - 2);
    return true;
  }

  if (a > b) { swap(a, b); }
  ll x = (int)(sqrt(a + 0.0) * sqrt(b + 0.0));
  while (x * x < a * b) x += 1;
  while (x * x >= a * b) x -= 1;
/*  vector <int> ind;
  ind.push_back(1);
  ind.push_back(a);
  ind.push_back(x);

  const int D = 100;

  int ans = 0;
  ll last_used = a * b + 1;
  for (int i = 1; i <= D && i < a - D; ++i) {
    ll maxP = min(last_used - 1, (a * b - 1 + i - 1) / i);
    if (maxP == b) {
      maxP--;
    }
    if (maxP > 0) {
      ans++;
    }
    last_used = maxP;
  }
  ans += max(0, (a - D) - D - 1);
  for (int i = a - D; i <= a + 2 * D && i < x - D; ++i) {
    ll maxP = min(last_used - 1, (a * b - 1 + i - 1) / i);
    if (maxP == b) {
      maxP--;
    }
    if (maxP > 0) {
      ans++;
    }
    last_used = maxP;
  }
  ans += max(0, (x - D) - (a + D) - 1);
  for (int i = x - D; i <= x; ++i) {
    ll maxP = min(last_used - 1, (a * b - 1 + i - 1) / i);
    if (maxP == b) {
      maxP--;
    }
    if (maxP > 0) {
      ans++;
    }
    last_used = maxP;
  }
*/
  dbg("a %lld b %lld x %lld\n", a, b, x);

  int ans = 2 * (x - 1);
  if (a < x) {
    ans -= 1;
  }
  {
    ll y = (a * b - 1) / b;
    if (y > 0 && y != a) {
      if ((a * b - 1) / y == b && (a * b - 1) / (y + 1) == b - 1) {
        ans -= 1;
      }
    }
  }

  if ((a * b - 1) / x == x) {
    if (x != a && x != b) {
      ans += 1;
    }
  } else {
    if (x != a && (a * b - 1) / x != b) {
      ans += 1;
    }
    ans += 1;
  }

  printf("%d\n", ans);

  return true;
}
/* 8 * 9 = 72


   1 71
   2 35
   3 23
   4 ??
   5 ??
   6 11
   7 10
   8 8
   

   */

int main() {
  scanf("%*d");
  while (solve());
  return 0;
}