#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
ll N,A,B;
  cin>>N>>A>>B;
  ll ans=0;
  for(ll i=1;i<=N;i++) {
string S=to_string(i);
    ll count=0;
    for(auto x:S) {
count+=x-'0';
    }
    if(count>=A&&count<=B) {
ans+=i;
    }
  }
  
  
  cout<<ans<<endl;
}
