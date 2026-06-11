#include <bits/stdc++.h>
using namespace std;
using ll=long long;
/*
4
3 4 3 2

      23
    345
  4567
678

*/
int main(){
  ll K; cin>>K;
  vector<ll> A(K,0),DP1(K,-1),DP2(K,-1);
  for(ll i=0; i<K; i++) cin>>A[i];
  if(A[K-1]>2){
    cout<<-1<<endl;
    return 0;
  }
  DP1[K-1]=2;
  DP2[K-1]=3;  
  //DP1
  for(ll i=K-2; i>=0; i--){
    ll n=DP1[i+1]/A[i];
    if(DP1[i+1]%A[i]>0) n++;
    DP1[i]=n*A[i];
  }
  //DP2
  for(ll i=K-2; i>=0; i--){
    ll n=DP2[i+1]/A[i];
    DP2[i]=(n+1)*A[i]-1;
  }
//for(ll i=0; i<K; i++)cout<<DP2[i]<<" ";  
  if(DP1[0]>DP2[0]){
    cout<<-1<<endl;
    return 0;
  }
  cout<<DP1[0]<<" "<<DP2[0]<<endl;
}