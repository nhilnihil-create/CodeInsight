#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=1LL<<61;

int main() {
  ll n;
  cin >> n;
  mat a(n,vec(n));
  for(ll i=0;i<n;i++) {
    for(ll j=0;j<n;j++) {
      cin >> a[i][j];
    }
  }
  mat dp(n+1,vec(1<<n));
  dp[0][0]=1;
  for(ll i=0;i<n;i++) {
    for(ll j=0;j<(1<<n);j++) {
      bitset<25> bit(j);
      if(bit.count()!=i) continue;
      for(ll k=0;k<n;k++) {
        if(!a[i][k]) continue;
        if(bit.test(k)) continue;
        (dp[i+1][j+(1<<k)]+=dp[i][j])%=mod;
      }
    }
  }
  cout << dp[n][(1<<n)-1] << endl;
}