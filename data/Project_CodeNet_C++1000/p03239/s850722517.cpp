#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  ll a,b;
  cin>>a>>b;
  vector<ll>vec(0);
  for(ll i=0;i<a;i++){
    ll c,d;
    cin>>c>>d;
    if(d<=b){
      vec.push_back(c);
    }
  }
  if(vec.size()==0){
    cout<<"TLE"<<endl;
  }
  else{
    sort(vec.begin(),vec.end());
    cout<<vec.at(0)<<endl;
  }
  return 0;
}
  
  
    
    
  
