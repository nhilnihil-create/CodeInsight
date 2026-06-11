#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  ll a;
  cin>>a;
  ll b=0;
  vector<ll>vec(a);
  for(ll i=0;i<a;i++){
    cin>>vec.at(i);
    b+=vec.at(i);
  }
  sort(vec.begin(),vec.end());
  cout<<b-vec.at(a-1)/2<<endl;
  return 0;
}
    
    
  
