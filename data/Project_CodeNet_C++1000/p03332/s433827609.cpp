#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll M = 998244353;

vector<ll> fac(300001);
vector<ll> ifac(300001);

ll mpow(ll x, ll n){
  ll ans = 1;
  while(n != 0){
    if(n&1) ans = ans*x % M;
    x = x*x % M;
    n = n >> 1;
    }
  return ans;
}

ll comb(ll a, ll b){
  if( a == 0 && b == 0) return 1;
  if( a < b || a <  0) return 0;
  ll tmp = ifac[a-b]* ifac[b] % M;
  return tmp*fac[a]%M;
}

int main(){
  ll n, k;
  ll  a, b;
  cin >> n >> a >> b >> k;

  fac[0] = 1;
  ifac[0] = 1;
  for(ll i = 0; i < 300000; i++){
    fac[i+1] = fac[i]*(i+1) % M;
    ifac[i+1] = ifac[i]*mpow(i+1, M-2) % M;
  }

  ll ans = 0;

  for(ll i = 0; i <= n; i++){
    if(a * i > k) break;
    if((k-a*i) < 0) continue;
    if((k - a*i)%b) continue;
    int t1 = i, t2 = (k - a*i)/b;
    if(t2 > n || t2 < 0) continue;
    ans = (ans + comb(n,t1)*comb(n,t2))%M;
    ans %= M;
  }
  if(ans < 0) ans = (ans+M)%M;
  cout << ans << endl;
  return 0;
}
