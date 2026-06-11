#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll a,b;
  cin>>a>>b;
  vector<ll>vec(a);
  double c=0;
  for(ll i=1;i<=a;i++){
    ll d=i;
    for(ll j=0;d<b;j++){
      d=d*2;
    }
    vec.at(i-1)=d/i;
  }
  sort(vec.begin(),vec.end());
  ll k=0;
  double g=vec.at(a-1);
  
  for(ll i=0;i<a;i++){
    k+=g/vec.at(i);
  }
  
  
    
  cout<<fixed<<setprecision(15);
  cout<<k/(a*g)<<endl;
      
  return 0;
}
