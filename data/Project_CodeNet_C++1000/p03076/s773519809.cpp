#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll ans=0;
 vector<ll> vec(5);
  for(ll i=0;i<5;i++) {
cin>>vec[i];
    ans+=vec[i];
  }
  
  vector<ll> R(5);
  for(ll i=0;i<5;i++) {
if(vec[i]%10==0) {
R[i]=0;
}
    else {
R[i]=10-vec[i]%10;
    }
  }
  
  sort(all(R));
  for(ll i=0;i<4;i++) {
ans+=R[i];
  }
  
  cout<<ans<<endl;
}
  
 