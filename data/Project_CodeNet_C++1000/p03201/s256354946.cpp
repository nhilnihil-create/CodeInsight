#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void del(map<ll,ll> &mp, ll val){
  mp[val]--;
  if(mp[val] == 0){ mp.erase(val);}
}

int main(){
  ll N; cin >> N; map<ll,ll> mp;
  ll ans = 0;
  vector<ll> A(N); 
  for(ll i = 0; i < N; i++){ 
    cin >> A[i]; mp[-A[i]]++;}
  
  for(ll i = 0; i < N && !mp.empty(); i++){
    ll a = -mp.begin()->first;
    del(mp,-a);
    ll p = 1;
    while( p <= a){ p *= 2;}
    ll rem = a-p;
    if(mp.count(rem)){
      ans++;
      del(mp,rem);}
  }
  
  cout << ans << endl;
  return 0;}
      