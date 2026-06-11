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
  mat d(cn,vec(cn));
  for(ll i=0;i<cn;i++) {
    for(ll j=0;j<cn;j++) {
      ll t;
      cin >> t;
      d[i][j]=t;
    }
  }
  mat c(n,vec(n));
  for(ll i=0;i<n;i++) {
    for(ll j=0;j<n;j++) {
      cin >> c[i][j];
      c[i][j]--;
    }
  }
  vector<map<ll,ll>> count(3);
  for(ll i=0;i<n;i++) {
    for(ll j=0;j<n;j++) {
      count[(i+j+2)%3][c[i][j]]++;
    }
  }
  ll ans=inf;
  for(ll i=0;i<cn;i++) {
    for(ll j=0;j<cn;j++) {
      if(i==j) continue;
      for(ll k=0;k<cn;k++) {
        if(i==k||j==k) continue;
        ll tans=0;
        for(auto p:count[0]) {
          tans+=d[p.first][i]*p.second;
        }
        for(auto p:count[1]) {
          tans+=d[p.first][j]*p.second;
        }
        for(auto p:count[2]) {
          tans+=d[p.first][k]*p.second;
        }
        ans=min(ans,tans);
      }
    }
  }
  cout << ans << endl;
}