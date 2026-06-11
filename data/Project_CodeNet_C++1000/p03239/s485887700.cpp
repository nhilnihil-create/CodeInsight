#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
ll N,T;
  cin>>N>>T;
  ll ans=100000;
  for(ll i=0;i<N;i++) {
ll c,t;
    cin>>c>>t;
    if(t<=T) {
      ans=min(ans,c);
    }
  }
  
  if(ans==100000) {
cout<<"TLE"<<endl;
    return 0;
  }
  cout<<ans<<endl;
}
