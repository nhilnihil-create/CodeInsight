#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()

 
int main() {
  ll X;
  cin>>X;
  ll ans=1;
  for(ll i=2;i<=sqrt(X);i++) {
ll a=i;
    while(a<=X) {
a*=i;
    }
    a/=i;
    ans=max(ans,a);
  }
  
  cout<<ans<<endl;
}
  
  