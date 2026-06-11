#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll N;
  cin>>N;
  vector<tuple<string,ll,ll>> vec(N);
  for(ll i=0;i<N;i++) {
string S;
    cin>>S;
    ll P;
    cin>>P;
    vec[i]=make_tuple(S,P,i+1);
  }
  
  sort(all(vec));
for (ll i=0;i<N;i++) {
if(get<0>(vec[i])!=get<0>(vec[i+1]) ){
  cout<<get<2>(vec[i])<<endl;
}
  
  else {
    ll count=0;
for(ll j=i+1;j<N;j++) {
if(get<0>(vec[j])==get<0>(vec[i])) {
count++;
}
              else {
break;
              }
              }
              
 for(ll h=0;h<=count;h++) {
   cout<<get<2>(vec[i+count-h])<<endl;
 }
              i+=count;
              }
              }
              }

              
              
              
              
              
              
              
              
              
              
              
              
  
  