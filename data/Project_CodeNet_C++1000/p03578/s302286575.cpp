#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll N;
  cin >> N;
  map<ll,ll> mp;
  for(ll i=0;i<N;i++){
    ll x;
    cin>>x;
    mp[x]+=1;
  }
  
  ll ans;
  cin>>ans;
  for(ll i=0;i<ans;i++){
    ll x;
    cin>>x;
    mp[x]-= 1;
  }
  
  for(auto m:mp){
    if(mp[m.first] < 0) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}
