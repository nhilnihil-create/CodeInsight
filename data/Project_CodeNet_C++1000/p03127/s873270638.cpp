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

int main() {
  
  ll a;
  cin>>a;
  vector<ll>vec(a);
  for(ll i=0;i<a;i++){
    cin>>vec.at(i);
  }
  sort(vec.begin(),vec.end());
  ll b=vec.at(0);
  for(ll i=0;i<a;i++){
    b=gcl(vec.at(i),b);
    if(b==1){
      cout<<b<<endl;
      return 0;
    }
  }
  cout<<b<<endl;
  return 0;
}
                             
    
