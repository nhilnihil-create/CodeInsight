#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  ll n; cin >> n;
  vector<ll> v;
  for(ll i = 1; i*i <= n; ++i){
    if(n%i==0)v.push_back(i);
    if(i*i == n)continue;
    if(n%i==0)v.push_back(n/i);
  }
  ll ans = 0;
  for(auto e:v){
    if(e==1)continue;
    ll m = e-1;
    ll x = n/e;
    if(n/m==x&&n%m==x)ans += m;
  }
  cout << ans << endl;
}