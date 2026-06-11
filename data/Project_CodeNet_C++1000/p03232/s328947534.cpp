#include <bits/stdc++.h>

#define N 100001
typedef long long ll;
const int MOD = 1e9 + 7;

inline int read() {
  int s = 0; char ch = getchar();
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) s = s * 10 + ch - '0', ch = getchar();
  return s;
}

int n;
int a[N];
ll fac[N], Inv[N];

inline void init() {
  Inv[1] = 1;
  for (int i = 2; i <= n; i++) {
    Inv[i] = (MOD - MOD / i) * Inv[MOD % i] % MOD;
  }
  for (int i = 2; i <= n; i++) {
    (Inv[i] += Inv[i - 1]) % MOD;
  }
}

int main() {
  n = read();
  init();
  for (int i = 1; i <= n; i++) a[i] = read();
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    ll tmp = (Inv[i] + Inv[n - i + 1] - 1) % MOD;
    tmp *= a[i];
    tmp %= MOD;
    ans = (ans + tmp) % MOD;
  }
  ll res = 1;
  for (int i = 1; i <= n; i++) res = res * i % MOD;
  printf("%lld\n", ans * res % MOD);
  return 0;
}