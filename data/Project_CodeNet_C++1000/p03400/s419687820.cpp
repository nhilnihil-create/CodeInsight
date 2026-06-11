#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()

 
int main() {
 ll N,D,X;
  cin>>N>>D>>X;
  ll ans=N;
  for(ll i=0;i<N;i++) {
ll A;
    cin>>A;
    ll count=0;
    ll k=1;
    while(A*k+1<=D) {
count++;
     
      k++;
    }
    ans+=count;
  
  }
  
  cout<<ans+X<<endl;
}
  
  

  
  
