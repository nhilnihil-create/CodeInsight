#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  ll a;
  cin>>a;
  vector<ll>vec(a);
  vector<ll>veco(a);
  for(ll i=0;i<a;i++){
    cin>>vec.at(i);
  }
  for(ll i=0;i<a;i++){
    cin>>veco.at(i);
  }
  ll b=0;
  for(ll i=0;i<a;i++){
    if(vec.at(i)>veco.at(i)){
      b+=vec.at(i)-veco.at(i);
    }
  }
  cout<<b<<endl;
  return 0;
}
