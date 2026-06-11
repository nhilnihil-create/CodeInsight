#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

map<ll,ll> bunkai(ll n){
  map<ll,ll> m;
  for(int i=1; i*i<=n; i++){
    if(n%i==0){
      m[i]=1;
      m[n/i]=1;
    }
  }
  return m;
}

int main(){
  
  int n,m; cin>>n>>m;
  auto s = bunkai(m);
  int ans{};
  for(auto k:s){
    
    if(m%k.first==0){
      if(n<=m/k.first){
        ans = max<ll>(ans,k.first);
      }
    }
  }
  cout << ans << endl;
}