#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll gcl(ll a,ll b){
  if(a%b==0){
    return b;
  }
  else{
    return gcl(b,a%b);
  }
}
int main(){
  ll a;
  cin>>a;
  ll b;
  cin>>b;
  vector<ll>vec(a);
  for(ll i=0;i<a;i++){
    ll c;
    cin>>c;
    vec.at(i)=abs(c-b);
  }
  if(a==1){
    cout<<vec.at(0)<<endl;
    return 0;
  }
  sort(vec.begin(),vec.end());
  ll g=gcl(vec.at(0),vec.at(1));
  for(ll i=0;i<a;i++){
    if(vec.at(i)%g==0){
      continue;
    }
    else{
      g=gcl(vec.at(i),g);
    }
  }
  cout<<g<<endl;
    
    
  
  return 0;
}

