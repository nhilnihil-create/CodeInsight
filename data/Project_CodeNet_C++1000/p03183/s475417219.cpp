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
  vec w(n),s(n),v(n);
  vector<pll> a(n);
  for(ll i=0;i<n;i++) {
    cin >> w[i] >> s[i] >> v[i];
    a[i]={w[i]+s[i],i};
  }
  sort(a.begin(),a.end());
  mat dp(n+1,vec(2e4+10));
  for(ll i=0;i<n;i++) {
    ll idx=a[i].second;
    for(ll j=0;j<=2e4;j++) {
      dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
      if(j) dp[i+1][j]=max(dp[i+1][j],dp[i+1][j-1]);
      if(j<=s[idx]&&j+w[idx]<=2e4) {
        dp[i+1][j+w[idx]]=max(dp[i+1][j+w[idx]],dp[i][j]+v[idx]);
      }
    }
  }
  cout << dp[n][2e4] << endl;
}