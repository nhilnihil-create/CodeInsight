#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=1000000007;
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
int main(){
  ll n;cin>>n;
  ll a[n];for(ll i=0;i<n;i++)cin>>a[i];
  ll ans=0;
  ll ki=1;
  for(ll i=1;i<=n;i++){
    ki*=i;
    ki%=mod;
  }
  ll sum=0;
  for(ll i=1;i<=n;i++){
    sum+=ki*gyaku(i);
    sum%=mod;
  }
  for(ll i=1;i<=n;i++){
    //cout<<sum<<endl;
    ans+=sum*a[i-1];
    ans%=mod;
    sum+=ki*gyaku(i+1);
    sum%=mod;
    sum-=ki*gyaku(n-i+1);
    sum%=mod;
    sum=(sum+mod)%mod;
  }
  cout<<ans<<endl;
}