#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  string S;
  cin>>S;
  ll ans=0;
  for(ll i=0;i<3;i++) {
if(S[i]=='1') {
ans++;
}
  }
  
  cout<<ans<<endl;
}