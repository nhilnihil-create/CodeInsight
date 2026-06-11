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
  ll n,m;
  cin >> n >> m;
  vec a(n);
  for(ll i=0;i<n;i++) {
    cin >> a[i];
  }
  a[0]%=m;
  for(ll i=0;i<n-1;i++) {
    (a[i+1]+=a[i])%=m;
  }
  map<ll,ll> count;
  for(ll i=0;i<n;i++) {
    count[a[i]]++;
  }
  ll ans=0;
  for(auto p:count) {
    ans+=p.second*(p.second-1)/2;
    if(p.first==0) {
      ans+=p.second;
    }
  }
  cout << ans << endl;
}