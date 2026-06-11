#include <bits/stdc++.h>
#include <boost/integer/common_factor_rt.hpp>
using namespace std;
using ll=long long;
const int MOD=1000000007;

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  map<int,int> m;
  for(ll i=0;i<n;i++){
    cin >> a.at(i);
    m[a.at(i)]++;
  }
  ll ans=0;
  for (auto p : m) {
    auto k = p.first;
    auto v = p.second;
    if(k>v)
    ans+=v;
    else 
    ans+=(v-k);
  }
  cout << ans << endl;
}