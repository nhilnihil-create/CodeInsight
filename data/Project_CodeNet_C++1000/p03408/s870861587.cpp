#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()

 
int main() {
 ll N,M;
  cin>>N;
  map<string,ll> B;
  map<string,ll> A;
  for(ll i=0;i<N;i++) {
string s;
    cin>>s;
    B[s]++;
  }
  cin>>M;
  for(ll i=0;i<M;i++) {
string t;
    cin>>t;
    A[t]++;
  }
   ll ans=0;
  for(auto x:B) {
    ll k=x.second-A[x.first];
    ans=max(ans,k);
  }
  
  cout<<ans<<endl;
}
