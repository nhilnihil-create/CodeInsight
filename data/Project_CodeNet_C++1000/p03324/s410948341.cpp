#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll D,N;
  cin>>D>>N;
  ll ans=1;
  for(ll i=0;i<D;i++) {
ans*=100;
  }
  if(N==100) {
ans*=101;
  }
  else {

  ans*=N;
  }
  cout<<ans<<endl;
}
  
  
  
