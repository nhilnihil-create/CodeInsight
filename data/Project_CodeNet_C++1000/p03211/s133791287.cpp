#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  string vec;
  cin>>vec;
  ll b=1000;
  ll x=vec.size();
  for(ll i=0;i<vec.size()-2;i++){
    ll c,d,e;
    c=vec.at(i)-'0';
    d=vec.at(i+1)-'0';
    e=vec.at(i+2)-'0';
    b=min(b,abs(100*c+10*d+e-753));
  }
  cout<<b<<endl;
  return 0;
}
    
    
  
