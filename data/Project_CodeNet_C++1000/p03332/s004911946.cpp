#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=998244353;
ll gyaku(ll n){
  ll u=mod-2;
  ll ret=1;
  ll now=n;
  while(u>0){
    if(u%2==1){
      ret*=now;
      ret%=mod;
    }
    now*=now;
    now%=mod;
    u/=2;
  }
  return ret;
}
ll nck(ll n,ll k){
  if(n<k)swap(n,k);
  if(2*k>n)k=n-k;
  ll ret=1;
  for(ll i=1;i<=k;i++){
    ret*=gyaku(i);
    ret%=mod;
  }
  for(ll i=0;i<k;i++){
    ret*=(n-i);
    ret%=mod;
  }
  return ret;
}
int main(){
  ll n,a,b,k;cin>>n>>a>>b>>k;
  ll ans=0;
  ll cc[n+1];
  cc[0]=1;
  for(ll i=1;i<=n;i++){
    cc[i]=cc[i-1]*gyaku(i);
    cc[i]%=mod;
    cc[i]*=(n-i+1);
    cc[i]%=mod;
  }
  
  for(ll i=0;i<=n;i++){
    ll u=k-i*a;
    if(u<0)break;
    if(u%b==0&&u/b<=n){
      ll sum=cc[i]*cc[u/b];
      sum%=mod;
      ans+=sum;
      ans%=mod;
    }
  }
  cout<<ans%mod<<endl;
}
     