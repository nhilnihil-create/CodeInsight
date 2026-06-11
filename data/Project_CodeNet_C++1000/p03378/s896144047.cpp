#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()

 
int main() {
  ll N,M,X;
  cin>>N>>M>>X;
  vector<ll> A(M+1);
  A[0]=X;
  for(ll i=1;i<=M;i++) {
    cin>>A[i];
  }
  sort(all(A));
  ll index;
  for(ll i=0;i<M+1;i++) {
    if(A[i]==X) {
      index=i;
    }
  }
  
  cout<<min(index,M-index)<<endl;
}



  
  