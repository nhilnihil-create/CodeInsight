#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define all(x) (x).begin(), (x).end()
#define MOD 998244353
#define MAX 500000
ll fac[MAX], finv[MAX], inv[MAX];
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
ll COM(ll n, ll k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
int main()
{
  ll n, a, b, k;
  ll ans = 0;
  cin >> n >> a >> b >> k;
  COMinit();
  for (ll r = 0; r <= n; r++)
  {
    if((k-r*a)%b==0){
      ll g = (k - r * a) / b;
      ans += COM(n, r) * COM(n, g);
      ans %= MOD;
    }
  }
  cout << ans << endl;
}
