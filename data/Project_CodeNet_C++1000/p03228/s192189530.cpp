#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(n);++i)

main(){

  ll a,b,k;
  cin>>a>>b>>k;
  rep(i,k){
    if(i&1){
      a+=b/2;
      b/=2;
    }else{
      b+=a/2;
      a/=2;
    }
  }
  cout<<a<<" "<<b<<endl;

}