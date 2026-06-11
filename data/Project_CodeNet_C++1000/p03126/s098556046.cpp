#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
ll N,M;
  cin>>N>>M;
  map<ll,ll> S;
  for(ll i=0;i<N;i++) {
    ll K;
    cin>>K;
    for(ll j=0;j<K;j++) {
      ll A;
      cin>>A;
      S[A]++;
    }
  }
  ll ans=0;
  for(auto x:S) {
if(x.second==N) {
ans++;
}
  }
  
  
  cout<<ans<<endl;
}

  
