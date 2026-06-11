#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(int)(a); i++)
typedef long long ll;
// const ll mod = 1000000007;
const ll mod = 998244353;
const ll INF = 1LL<<60;

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

int main()
{
  ll n,a,b,k; cin>>n>>a>>b>>k;
  cominit();
  ll ans = 0;
  for (ll i=0; i<=n; i++) {
    ll t = k - a*i;
    if (t%b != 0) continue;
    ll j = t/b;
    ans = (ans + (com(n,i)*com(n,j)%mod)) % mod;
  }
  cout << ans << endl;

  return 0;
}
