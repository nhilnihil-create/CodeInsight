#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()

 
int main() {
 vector<ll> vec(3);
  for(ll i=0;i<3;i++) {
    cin>>vec[i];
  }
  sort(all(vec));
  ll K;
  cin>>K;
  ll count=0;
  while(count<K) {
vec[2]*=2;
    count++;
  }
  
  ll ans=0;
  for(auto x:vec) {
ans+=x;
  }
  cout<<ans<<endl;
}
  
  