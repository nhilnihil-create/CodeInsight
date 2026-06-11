#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 300300;
const int mod = 998244353;
#define int long long
#define M(x) (((x) + mod) % mod)

int n, a, b, k, c[N], inv[N], s[N], t[N], fac[N], ans, inv2[N];

inline int qpow(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) (res *= a) %= mod;
    (a *= a) %= mod, b >>= 1;
  }
  return res;
}

inline void prework() {
  fac[0] = s[0] = 1; inv[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  for (int i = 1; i <= n; i++) s[i] = 1ll * s[i - 1] * fac[i] % mod;
  t[n] = qpow(s[n], mod - 2);
  for (int i = n; i >= 1; i--) t[i - 1] = 1ll * t[i] * fac[i] % mod;
  for (int i = 1; i <= n; i++) inv[i] = 1ll * t[i] * s[i - 1] % mod;
}

inline ll C(int M, int N) {
  if (N < 0 || N > M) return 0;
  return M(1ll * fac[M] * M(inv[N] * inv[M - N]));
}

signed main() {
  scanf("%lld%lld%lld%lld", &n, &a, &b, &k);
  prework();
  for (int x = 0, y; x <= n; x++)
    if ((k - a * x) % b == 0) {
      y = (k - a * x) / b;
      ans += M(1ll * C(n, x) * C(n, y));
    }
  printf("%lld\n", M(ans));
  return 0;
}