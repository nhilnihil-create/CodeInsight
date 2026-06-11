#include <stdio.h>
#define mod 1000000007
typedef long long ll;

ll exp(ll a, ll b) {
  ll ans = 1;
  while(b) {
    if(b & 1) ans *= a;
    a *= a, b >>= 1, ans %= mod, a %= mod;
  }
  return ans;
}

int main(void) {
  ll i, j, k, n, ans = 0, a;
  scanf("%lld", &n);
  ll rev[n + 10], fact = 1;
  rev[0] = 0;
  for(i = 1; i <= n; ++i) {
    rev[i] = exp(i, mod - 2), rev[i] += rev[i - 1], rev[i] %= mod;
    fact *= i, fact %= mod;
  }
  for(i = 1; i <= n; ++i) {
    scanf("%lld", &a);
    ans += (a * (rev[i] + rev[n - i + 1] - 1)) % mod * fact;
    ans %= mod;
  }
  printf("%lld", ans);
  return  0;
}