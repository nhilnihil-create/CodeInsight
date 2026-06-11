#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define rep1(i, n) for(ll i = 1; i < n+1; i++)
#define all(A) A.begin(),A.end()
typedef long long ll;

int main(){
  ll n,m;
  cin >> n >> m;
  map<ll,ll> mp;
  mp[0]++;
  ll s = 0;
  rep(i,n){
    ll a;
    cin >> a;
    s += a;
    mp[s%m] ++;
  }
  ll ans = 0;
  for(auto p : mp){
    ll now = p.second;
    ans += now*(now-1)/2;
  }
  cout << ans << endl;
}