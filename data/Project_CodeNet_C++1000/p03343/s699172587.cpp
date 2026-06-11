// Author: 23forever
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
typedef long long LL;
const int MAXN = 200000;
const int INF = 0x3f3f3f3f;
using namespace std;

inline void enableFileIO() {
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
}

inline int read() {
  int x = 0, w = 1;
  char c = ' ';

  while (c < '0' || c > '9') {
    c = getchar();
    if (c == '-') w = -1;
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }

  return x * w;
}

int n, q, k;
int a[MAXN + 5], tmp[MAXN + 5];
int b[MAXN + 5], c[MAXN + 5];

void init() {
  //enableFileIO();

  n = read();
  k = read();
  q = read();
  for (int i = 1; i <= n; ++i) tmp[i] = a[i] = read(); 
}

inline int calc(int mn) {
  int tot = 0, l = 1, r = 1;
  while (l <= n) {
    while (a[l] < mn && l <= n) ++l;
    r = l;
    while (a[r] >= mn && r <= n) ++r;
    
    int len = 0;
    for (int i = l; i < r; ++i) b[++len] = a[i];
    if (len >= k) {
      sort(b + 1, b + 1 + len);
      for (int i = 1; i <= len - k + 1; ++i) c[++tot] = b[i];
    }
    l = r;
  }

  sort(c + 1, c + 1 + tot);
  if (tot >= q) {
    return c[q] - c[1];
  } else {
    return INF;
  }
}

int main() {
  init();

  sort(tmp + 1, tmp + 1 + n);
  int ans = INF;
  for (int i = 1; i <= n; ++i) {
    ans = min(ans, calc(tmp[i]));
  }

  printf("%d\n", ans);
  return 0;
}