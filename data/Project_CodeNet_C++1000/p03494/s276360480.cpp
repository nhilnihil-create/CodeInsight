#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
ll N;
  cin>>N;
  ll ans=30;
  for(ll i=0;i<N;i++) {
ll A;
    cin>>A;
    ll count=0;
    while(A%2==0) {
A/=2;
      count++;
    }
    ans=min(ans,count);
  }
  
  
  cout<<ans<<endl;
}
    
    