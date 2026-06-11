#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
 string S;
  cin>>S;
  ll ans=1000;
  for(ll i=0;i<S.size()-2;i++) {
  ll b=abs(('7'-S[i])*100+('5'-S[i+1])*10+'3'-S[i+2]);
    ans=min(ans,b);
  }
  
  cout<<ans<<endl;
}
