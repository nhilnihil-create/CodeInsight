#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  ll a;
  cin>>a;
  vector<pair<pair<string,ll>,ll>>vec(a);
  for(ll i=0;i<a;i++){
    cin>>vec.at(i).first.first;
    ll g;
    cin>>g;
    vec.at(i).first.second=100-g;
    vec.at(i).second=i;
  }
  sort(vec.begin(),vec.end());
  
  for(ll i=0;i<a;i++){
    cout<<vec.at(i).second+1<<endl;
  }
  return 0;
}