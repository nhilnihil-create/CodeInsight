#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
 ll N;
  cin>>N;
  vector<vector<ll>> vec(2,vector<ll>(N));
  for(ll i=0;i<2;i++) {
for(ll j=0;j<N;j++) {
  cin>>vec[i][j];
}
  }
  
  ll ans=0;
  
  
  for(ll i=0;i<N;i++) {
if(vec[0][i]-vec[1][i]>0) {
  ans+=vec[0][i]-vec[1][i];
}
  }
  
  
  cout<<ans<<endl;
}

  
