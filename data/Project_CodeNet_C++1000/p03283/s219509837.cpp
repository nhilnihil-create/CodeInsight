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
  ll n,m,q;
  cin >> n >> m >> q;
  mat lr(n+2,vec(n+2));
  for(ll i=0;i<m;i++) {
    ll l,r;
    cin >> l >> r;
    lr[l][r]++;
  }
  for(ll i=0;i<n;i++) {
    for(ll j=0;j<=n;j++) {
      lr[i+1][j]+=lr[i][j];
    }
  }
  for(ll i=0;i<=n;i++) {
    for(ll j=0;j<n;j++) {
      lr[i][j+1]+=lr[i][j];
    }
  }
  while(q--) {
    ll l,r;
    cin >> l >> r;
    cout << lr[r][r]-lr[r][l-1]-lr[l-1][r]+lr[l-1][l-1] << endl;
  }
}