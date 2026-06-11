#include <bits/stdc++.h>

using namespace std;

namespace FastRead {
  const int Dim(5000);
  char ibuf[Dim];
  int ipos, ilen;
  char nc() {
    if (ipos == ilen) {
      ipos = 0;
      ilen = fread(ibuf, 1, Dim, stdin);
      if (!ilen) return EOF;
    }
    return ibuf[ipos++];
  }
  template<class T> void read(T& x) {
    char ch;
    int sgn = 1;
    while (!isdigit(ch = nc()))
      if (ch == '-')
        sgn = -1;
    x = ch - '0';
    while (isdigit(ch = nc()))
      x = x * 10 + (ch - '0');
    x *= sgn;
  }
}
using namespace FastRead;

int main () {
  int N;
  read(N);
  int Size = 1;
  while (Size <= N)
    Size <<= 1;
  vector < long long > Tree (Size << 1);
  vector < int > h(N), a(N);
  for (int i = 0; i < N; ++i)
    read(h[i]);
  for (int i = 0; i < N; ++i)
    read(a[i]);
  vector < long long > dp(N + 1);
  for (int flower = 0; flower < N; ++flower) {
    int x = h[flower] + Size;
    long long best = 0;
    while (x > 1) {
      if (x & 1)
        best = max (best, Tree[x - 1]);
      x >>= 1;
    }
    dp[h[flower]] = best + a[flower];
    for (int i = Size + h[flower]; i > 0; i >>= 1)
      Tree[i] = max (Tree[i], dp[h[flower]]);
  }
  long long ans = 0;
  for (int i = 0; i <= N; ++i)
    ans = max (ans, dp[i]);
  cout << ans;
}
