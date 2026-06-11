#include<bits/stdc++.h>
#define ll long long
using namespace std;
signed main(){
  ll a,b,k;
  cin>>a>>b>>k;
  for(ll i=a;i<=min(b,a+k-1);i++){
    cout<<i<<"\n";
  }
  for(ll i=max(b-k+1,a+k);i<=b;i++){
    cout<<i<<"\n";
  }
  return 0;
}