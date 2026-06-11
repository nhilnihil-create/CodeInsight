#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  ll a;
  cin>>a;
  ll c;
  cin>>c;
  vector<ll>vec(a);
  for(ll i=0;i<a;i++){
    cin>>vec.at(i);
  }
  sort(vec.begin(),vec.end());
  ll b=vec.at(a-1);
  for(ll i=c-1;i<a;i++){
    b=min(b,vec.at(i)-vec.at(i-c+1));
  }
  cout<<b<<endl;
  return 0;
}
    
    
  
