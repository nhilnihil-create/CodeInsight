#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()

 
int main() {
 ll N,X;
  cin>>N>>X;
  vector<ll> vec(N);
  ll ans=N;
  
  for(ll i=0;i<N;i++) {
cin>>vec[i];
    X-=vec[i];
  }
  sort(all(vec));
  
  ans+=X/vec[0];
cout<<ans<<endl;
}
  