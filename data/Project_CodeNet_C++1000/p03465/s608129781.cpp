#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

template <typename T>
inline void chkmax(T &x, T y) { if (x < y) x = y; }

template <typename T>
inline void chkmin(T &x, T y) { if (x > y) x = y; }

inline int read() {
  #define nc getchar()
  int x = 0;
  char c = nc;
  while (c < 48) c = nc;
  while (c > 47) x = x * 10 + (c ^ 48), c = nc;
  return x;
  #undef nc
}

typedef long long ll;
const int maxn = 2010;
int n, A[maxn];

bitset <maxn * maxn> dp;

void solve() {
  cin >> n;
  int sum = 0;
  rep(i, 1, n) {
    A[i] = read(), sum += A[i];
  }
  dp[0] = 1;
  rep(i, 1, n) dp |= dp << A[i];
  int pos = (sum - 1) / 2 + 1;
  while (pos < sum && !dp[pos]) pos++;
  printf("%d\n", pos);
}

int main() {
//  int T = read();
//  while (T--) solve();
  solve();
  return 0;
}