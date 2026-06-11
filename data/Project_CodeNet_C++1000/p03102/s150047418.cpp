#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll N,M,C;
  cin>>N>>M>>C;
  vector<ll> B(M);
  for(ll i=0;i<M;i++) {
cin>>B[i];
  }
  ll ans=0;
  for(ll i=0;i<N;i++) {
    ll sum=C;
for(ll j=0;j<M;j++) {
  ll A;
  cin>>A;
  sum+=A*B[j];
}
    
    if(sum>0) {
ans++;
    }
  }
  
  cout<<ans<<endl;
}
  
  