#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll N;
  cin>>N;
  vector<ll> A(N);
  for(ll i=0;i<N;i++) {
cin>>A[i];
  }
  sort(all(A));
  reverse(all(A));
  ll ans=0;
  for(ll i=0;i<N-1;i+=2) {
    ans+=A[i]-A[i+1];
  }
  
  if(N%2!=0) {
ans+=A.back();
  }
  
  cout<<ans<<endl;
}
