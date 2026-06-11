#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod=998244353;
ll mod_conb[500005]={0};
ll npr[500005]={0},gyk[500005]={0};
ll pow(ll x,ll y){
  if(y==0) return 1;
  ll ret=pow(x,y/2);
  ret*=ret;
  ret%=mod;
  if(y%2==1) ret*=x;
  ret%=mod;
  return ret;
}
int main(){
  ll n,a,b,k;
  cin>>n>>a>>b>>k;
  if(k==0){
    cout<<1<<endl;
    return 0;
  }
  npr[0]=1;
  npr[1]=n;
  for(ll i=1;i<n;i++) npr[i+1]=(npr[i]*(n-i))%mod;
  gyk[n]=pow(npr[n],mod-2)%mod;
  for(ll i=n;i>=1;i--) gyk[i-1]=(gyk[i]*i)%mod;
  for(ll i=0;i<=n;i++){
    mod_conb[i]=(npr[i]*gyk[i])%mod;
  }
  ll ans=0;
  for(ll i=0;i<=n;i++){
    if(a*i>k) continue;
    if((k-a*i)%b!=0) continue;
    ll j=(k-a*i)/b;
    if(j>n) continue;
    ans+=(mod_conb[i]*mod_conb[j])%mod;
    ans%=mod;
  }
  cout<<ans<<endl;
}
