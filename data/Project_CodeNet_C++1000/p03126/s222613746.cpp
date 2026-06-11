#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
  ll a,b;
  cin>>a>>b;
  vector<ll>vec(b);
  for(ll i=0;i<a;i++){
    ll c;
    cin>>c;
    for(ll j=0;j<c;j++){
      ll d;
      cin>>d;
      vec.at(d-1)+=1;
    }
  }
  ll e=0;
  for(ll i=0;i<b;i++){
    if(vec.at(i)==a){
      e+=1;
    }
  }
  cout<<e<<endl;
    
  return 0;
}
                             
    
