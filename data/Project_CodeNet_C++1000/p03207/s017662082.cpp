#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
 ll N;
  cin>>N;
 vector<ll> vec(N);
  for(ll i=0;i<N;i++) {
cin>>vec[i];
  }
  
  sort(all(vec));
  ll ans=0;
  for(ll i=0;i<N-1;i++) {
ans+=vec[i];
  }
  
  
  ans+=vec[N-1]/2;
  
  cout<<ans<<endl;
}
  
