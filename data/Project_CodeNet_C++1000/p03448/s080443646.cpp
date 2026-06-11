#include<bits/stdc++.h>
#define ll long long
using namespace std;
signed main(){
  ll a,b,c,x,cun=0;
  cin>>a>>b>>c>>x;
  for(ll i=0;i<=a;i++){
    for(ll j=0;j<=b;j++){
      for(ll k=0;k<=c;k++){
        if(500*i + 100*j + 50*k == x){
          cun++;
        }
      }
    }
  }
  cout<<cun<<"\n";
  return 0;
}