#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  ll a;
  cin>>a;
  vector<string>vec(a);
  vector<ll>veco(a);
  for(ll i=0;i<a;i++){
    cin>>vec.at(i)>>veco.at(i);
  }
  vector<ll>new1(a);
  for(ll i=0;i<a;i++){
    ll b=0;
    for(ll j=0;j<a;j++){
      if(vec.at(j)<vec.at(i)){
        b+=1;
        
      }
      else if(vec.at(i)==vec.at(j)){
        if(veco.at(j)>veco.at(i)){
          b+=1;
        }
      }
    }
    new1.at(b)=i+1;
  }
  for(ll i=0;i<a;i++){
    cout<<new1.at(i)<<endl;
  }
  
  return 0;
    
  
      
  
  
    
}