#include "bits/stdc++.h"
#include "math.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
const int INF=1e9;
ll devine(ll x,ll y){
  if(x<0&&y<0){
    if(x%y<0){return (x/y)+1;}
  }
  return x/y;
}
ll amari(ll x,ll y){
  if(x<0&&y<0){
    if(x%y<0){return (x%y)-y;}
  }
  return x%y;
}
int main(){
  ll n,m,ans=0;
  cin>>n>>m;
  vll a(n),sum(n+1,0);
  set<ll> s;
  rep(i,0,n){
    cin>>a[i];a[i]%=m;
    sum[i+1]=sum[i]+a[i];
    sum[i+1]%=m;
    s.insert(sum[i]);
  }
  sort(sum.begin(),sum.end());
  auto itset=s.begin();
  rep(i,0,s.size()){
    auto it=upper_bound(sum.begin(),sum.end(),*(itset))-lower_bound(sum.begin(),sum.end(),*(itset));
    ans+=(it*(it-1))/2;
    itset++;
  }
  cout<<ans<<endl;
}