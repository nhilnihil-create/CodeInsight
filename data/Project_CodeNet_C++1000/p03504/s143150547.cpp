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
  ll n,cn;
  cin >> n >> cn;
  vector<pair<pll,ll>> a(n);
  for(ll i=0;i<n;i++) {
    ll s,t,c;
    cin >> s >> t >> c;
    c--;
    a[i]={pll(s,t),c};
  }
  sort(a.begin(),a.end());
  ll ans=0;
  ll idx=0;
  ll temp=0;
  vec q(cn,-1);
  for(ll i=0;i<1e5+10;i++) {
    while(idx<n&&a[idx].first.first<=i) {
      if(q[a[idx].second]<0) {
        temp++;
      }
      q[a[idx].second]=max(q[a[idx].second],a[idx].first.second);
      idx++;
    }
    ans=max(ans,temp);
    
    for(ll j=0;j<cn;j++) {
      if(q[j]==i) {
        temp--;
        q[j]=-1;
      }
    }
  }
  cout << ans << endl;
}