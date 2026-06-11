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

vector < long long > aib;

long long Query (int poz) {
  long long ans = 0;
  while (poz > 0) {
    ans = max (ans, aib[poz]);
    poz -= poz & (-poz);
  }
  return ans;
}

void Update (int poz, long long val) {
  while (poz < (int)aib.size()) {
    aib[poz] = max (aib[poz], val);
    poz += poz & (-poz);
  }
}

int main () {
  int N;
  read(N);
  vector < int > h(N), a(N);
  for (int i = 0; i < N; ++i)
    read(h[i]);
  for (int i = 0; i < N; ++i)
    read(a[i]);
  aib.resize(N + 2);
  vector < long long > dp(N + 1);
  for (int i = 0; i < N; ++i) {
    long long best = Query (h[i] + 1) + a[i];
    if (best > dp[h[i]]) {
      dp[h[i]] = best;
      Update (h[i] + 1, dp[h[i]]);
    }
  }
  long long ans = 0;
  for (int i = 0; i <= N; ++i)
    ans = max (ans, dp[i]);
  cout << ans;
}
