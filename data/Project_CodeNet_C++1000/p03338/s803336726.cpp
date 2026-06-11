#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
ll N;
  cin>>N;
  string S;
  cin>>S;
  ll ans=0;
  for(ll i=0;i<N-1;i++) {
    set<char> s;
for(ll j=0;j<=i;j++) {
  s.insert(S[j]);
}
    
    ll count=0;
    for(ll h=i+1;h<N;h++) {
      if(s.count(S[h])) {
        s.erase(S[h]);
        count++;
      }
         }
         
         ans=max(ans,count);
         }
         
         cout<<ans<<endl;
         }
         

      
      


  
  
  
  
