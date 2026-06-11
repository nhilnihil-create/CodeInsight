#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int MAX = 510000;
ll fac[MAX], finv[MAX], inv[MAX];
 
void cominit()
{
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (ll i=2; i<MAX; i++) {
    fac[i] = fac[i-1] * i % mod;
    inv[i] = mod - inv[mod%i] * (mod/i) % mod;
    finv[i] = finv[i-1] * inv[i] % mod;
  }
}
 
ll com(ll n, ll k)
{
  if (n<k) return 0;
  if (n<0 || k<0) return 0;
  return fac[n] * (finv[k] * finv[n-k] % mod) % mod;
}

int main(){
    ll n, a, b, k;
    cin >> n >> a >> b >> k;
    ll ans = 0;

    cominit();

    for(ll i = 0; i <= k; i += a){
        if((k-i)%b==0){
            ans += com(n, i/a)%mod*com(n, (k-i)/b)%mod;
            ans %= mod;
        }
    }
    cout << ans%mod << endl;
}