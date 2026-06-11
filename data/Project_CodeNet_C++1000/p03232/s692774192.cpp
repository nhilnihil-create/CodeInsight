#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;
const int MOD = (int)1e9 + 7;

int n, a[MAXN], fac[MAXN], inv[MAXN], sum[MAXN];

int fexp(int x, int y) {
  int res = 1;
  for(int i = 1; i <= y; i <<= 1) {
    if(i & y) res = 1LL * res * x % MOD;
    x = 1LL * x * x % MOD;
  }
  return res;
}

int calc(int t) {
  return 1LL * fac[n] * inv[t + 1] % MOD;  
}

void init(int n) {
  fac[0] = inv[0] = 1;
  for(int i = 1; i <= n; i++) {
    fac[i] = 1LL * fac[i - 1] * i % MOD;
    inv[i] = fexp(i, MOD - 2);
  }
  sum[0] = calc(0);
  for(int i = 1; i < n; i++) {
    sum[i] = (sum[i - 1] + calc(i)) % MOD;
  }
}


int main() {
  scanf("%d", &n);
  init(n);
  for(int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    int tot = (sum[i - 1] + sum[n - i] % MOD - sum[0]) % MOD;
    ans = (ans + 1LL * tot * a[i] % MOD) % MOD;
  }
  printf("%d\n", (ans + MOD) % MOD);
  return 0;
}
