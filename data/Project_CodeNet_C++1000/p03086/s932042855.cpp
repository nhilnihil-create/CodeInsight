#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  string S;
  cin>>S;
  ll N=S.size();
  
  ll ans=0;
  for(ll i=0;i<N;i++) {
    ll count=0;
    if(S[i]=='A'||S[i]=='T'||S[i]=='G'||S[i]=='C') {
count++;
    for(ll j=i+1;j<N;j++) {
      if(S[j]=='A'||S[j]=='T'||S[j]=='G'||S[j]=='C') {
count++;
      }
      else {
break;
      }
    }
      ans=max(ans,count);
    }
  }
  
  
  
  cout<<ans<<endl;
}
      
      
      
      
      
      
      
      
      
      
      

