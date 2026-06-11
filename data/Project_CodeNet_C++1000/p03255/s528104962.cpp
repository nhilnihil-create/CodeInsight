#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

const long long inf = 1'000'000'000'000'000'000;

inline long long mul(long long a, long long b) {
  return a <= inf / b ? a * b : inf;
}

inline long long add(long long a, long long b) {
  a += b;
  return a <= inf ? a : inf;
}

const int N = 200'009;

int n;
int a[N];

long long calc(int s) {
  long long res = 0;
  for (int i = 0; i < s; ++i) {
    res = add(res, a[i]);
  }
  for (int from = 0; from < n; from += s) {
    for (int k = 0; k < s; ++k) {
      int i = from + k;
      if (i >= n) {
        continue;
      }
      int j = from + s + k;
      int v = from / s + 2;
      if (j < n) {
        res = add(res, mul(a[i] - a[j], mul(v, v)));
      } else {
        res = add(res, mul(a[i], mul(v, v)));
      }
    }
  }
  return res;
}

int main() {
  int m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  reverse(a, a + n);
  int ll = 0, rr = n + 1;
  while (rr - ll > 1) {
    int ss = (ll + rr) / 2;
    if (calc(ss) == inf) {
      ll = ss;
    } else {
      rr = ss;
    }
  }
  int l = ll + 1, r = n;
  while (l < r) {
    int s = (l + r) / 2;
    if (calc(s) + (long long)m * s > calc(s + 1) + (long long)m * (s + 1)) {
      l = s + 1;
    } else {
      r = s;
    }
  }
  printf("%lld\n", calc(l) + (long long)m * (l + n));
}
