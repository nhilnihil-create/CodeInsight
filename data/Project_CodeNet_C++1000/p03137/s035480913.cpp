#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  ll a,b;
  cin>>a>>b;
  if(a>=b){
    cout<<0<<endl;
    
    return 0;
  }
  vector<ll>vec(b);
  for(ll i=0;i<b;i++){
    cin>>vec.at(i);
  }
  sort(vec.begin(),vec.end());
  vector<ll>veco(b-1);
  for(ll i=0;i<b-1;i++){
    veco.at(i)=vec.at(i+1)-vec.at(i);
  }
  sort(veco.begin(),veco.end());
  ll c=0;
  for(ll i=0;i<b-a;i++){
    c+=veco.at(i);
  }
  cout<<c<<endl;
    
  return 0;
}