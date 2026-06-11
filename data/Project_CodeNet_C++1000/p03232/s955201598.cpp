#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll pow(ll x,ll y){
  if(y==0) return 1;
  ll res=pow(x,y/2);
  res*=res;
  res%=mod;
  if(y%2==1) res*=x;
  return res%mod;
}
ll gyaku(ll x){
  return pow(x,mod-2);
}
vector<ll> frac,gfrac;
void set_frac(ll n){
  frac.push_back(1);
  gfrac.push_back(1);
  for(ll i=1;i<=n;i++){
    frac.push_back(frac[i-1]*i%mod);
    gfrac.push_back(gyaku(frac[i]));
  }
}
ll nCr(ll n,ll r){
  ll res=frac[n]*gfrac[r]%mod;
  res*=gfrac[n-r];
  return res%mod;
}
int main(){
  vector<ll> gv;
  gv.push_back(0);
  ll n;
  cin>>n;
  for(ll i=1;i<=n;i++) gv.push_back((gv[i-1]+pow(i,mod-2))%mod);
  ll ans=0;
  for(int i=1;i<=n;i++){
    ll a;
    cin>>a;
    ans+=(a*(gv[i]+gv[n-i+1]-1))%mod;
  }
  for(ll i=1;i<=n;i++){
    ans*=i;
    ans%=mod;
  }
  cout<<ans<<endl;
}
