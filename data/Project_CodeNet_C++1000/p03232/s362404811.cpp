#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
#define dbg(x) cout<<#x<<":"<<x<<endl
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> PP;

ll mod_pow(ll x,ll n,ll mod){
  if(n==0)return 1;
  ll res=mod_pow( x*x%mod , n/2 , mod );
  if( n & 1 )res = res*x%mod;
  return res;
}

int main(){
  ll n,a[111111];
  ll p=1e9+7;
  
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }

  ll inv[111111];
  inv[0]=0;
  ll exn=1;
  for(ll i=1;i<=n;i++){
    inv[i]=mod_pow(i,p-2,p);
    if(i>1){
	 inv[i]+=inv[i-1];
	 inv[i]%=p;
    }
    exn*=i;
    exn%=p;
  }

  
  
  ll ans=0;
  for(int i=0;i<n;i++){
    ans+=(((exn*inv[i+1])%p)*a[i])%p;
    ans%=p;
    ans+=(((exn*inv[n-i])%p)*a[i])%p;
    ans%=p;
    ans=(p+ans-(exn*a[i])%p)%p;
  }

  cout<<ans<<endl;
  return 0;
}
