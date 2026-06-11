#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
 ll N,M;
  cin>>N>>M;
  map<ll,ll> S;
  for(ll i=0;i<N;i++) {
ll A;
    cin>>A;
    S[A]++;
  }
  
  for(ll i=0;i<M;i++) {
ll B,C;
    cin>>B>>C;
    S[C]+=B;
  }
  
  vector<pair<ll,ll>> vec(0);
  for(auto x:S) {
    vec.push_back(x);
  }

  sort(all(vec));
  reverse(all(vec));
  ll ans=0;
  ll count=0;
  ll i=0;
  while(count<N) {
    if(vec[i].second+count>N) {
ans+=vec[i].first*(N-count);
      break;
    }
ans+=vec[i].first*vec[i].second;
    count+=vec[i].second;
    i++;
  }

  cout<<ans<<endl;
}
  
  