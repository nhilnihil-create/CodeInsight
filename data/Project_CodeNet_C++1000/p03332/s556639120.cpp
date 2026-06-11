#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)

const ll mod=998244353;
ll mu(ll a,ll b){
  return (ll)a*b%mod;
}
ll ad(ll a,ll b){
  if((a+=b)>=mod)a%=mod;
  return a;
}
ll pw(ll a,ll b,ll c=1LL){
  for(;b;b>>=1,a=mu(a,a))if(b&1)c=mu(c,a);
  return c;
}
ll dv(ll a,ll b){
  return mu(a,pw(b,mod-2));
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll n,a,b,k;
  cin >> n >> a >> b >> k;

  vector<ll> fact(n+1);
  vector<ll> inv(n+1);
  fact[0]=1;
  rep1(i,n) fact[i] = mu(fact[i-1],i);
  rep(i,n+1) inv[i] = dv(1,fact[i]);
  ll ans=0;
  rep(l,n+1){
    ll m = (k-l*a)/b;
    if(l*a+m*b==k && m>=0 && m<=n){
      //      cout << "l m "<< l << " " << m << endl;
      ans = ad(ans,mu(mu(mu(fact[n],inv[l]),inv[n-l]), mu(mu(fact[n],inv[m]),inv[n-m]) ));
    }
  }
    cout << ans << endl;
  
  return 0;
    

}
