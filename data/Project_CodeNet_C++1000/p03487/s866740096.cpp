#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll n;
  cin >> n;
  map<ll,ll> mp;
  rep(i,n){
    ll a;
    cin >> a;
    mp[a]++;
  }
  ll ans=0;
  for(auto p: mp){
    if(p.first<p.second){
      ans+=p.second-p.first;
    }else if(p.first>p.second){
      ans+=p.second;
    }
  }
  cout << ans;
}
 