#include <stdio.h>
#define mod 998244353
typedef long long ll;

ll fact[300001];

ll mul(ll a, ll b) {
  return a * b % mod;
}

ll rev(ll a) {
  ll ans = 1, b = mod - 2;
  while(b) {
    if(b & 1) ans = mul(ans, a);
    a = mul(a, a), b >>= 1;
  }
  return ans;
}

ll cmb(ll a, ll b) {
  return mul(fact[a], mul(rev(fact[b]), rev(fact[a - b])));
}

ll gcd(ll a, ll b) {
  ll t;
  while(b) t = a % b, a = b, b = t;
  return a;
}

int main(void) {
  ll i, j, k, n, a, b, ans = 0;
  scanf("%lld%lld%lld%lld", &n, &a, &b, &k);
  fact[0] = 1;
  for(i = 1; i <= n; ++i) fact[i] = mul(fact[i - 1], i);
  for(i = 0; i <= n && a * i <= k; ++i) if(!((k - a * i) % b) && (k - a * i) / b <= n) {
    ans += mul(cmb(n, i), cmb(n, (k - a * i) / b));
    ans %= mod;
  }
  printf("%lld", ans);
  return 0;
}