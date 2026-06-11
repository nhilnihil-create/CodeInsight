#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=5e18;

int main() {
  ll n;
  string s;
  cin >> n >> s;
  map<char,ll> count;
  for(ll i=0;i<n;i++) {
    count[s[i]]++;
  }
  ll ans=1;
  for(auto p:count) {
    ans=ans*(p.second+1)%mod;
  }
  ans=(ans-1+mod)%mod;
  cout << ans << endl;
}