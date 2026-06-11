#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  ll a,b,C;
  cin>>a>>b>>C;
  vector<ll>vec(b);
  for(ll i=0;i<b;i++){
    cin>>vec.at(i);
  }
  ll c=0;
  for(ll i=0;i<a;i++){
    ll d=C;
    for(ll j=0;j<b;j++){
      ll e;
      cin>>e;
      d+=e*vec.at(j);
    }
    
    if(d>0){
      c+=1;
    }
  }
  cout<<c<<endl;
      
  return 0;
}
