#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=1LL<<61;

typedef pair<pll,ll> ppll;

int main() {
  ll n;
  cin >> n;
  vector<ppll> a(n);
  for(ll i=0;i<n;i++) {
    ll w,s,v;
    cin >> w >> s >> v;
    a[i]={{w+s,s},v};
  }
  sort(a.begin(),a.end());
  mat dp(n+1,vec(2e4+10));
  for(ll i=0;i<n;i++) {
    ll w=a[i].first.first-a[i].first.second;
    ll s=a[i].first.second;
    ll v=a[i].second;
    for(ll j=0;j<=2e4;j++) {
      dp[i+1][j]=dp[i][j];
      if(j>=1) dp[i+1][j] = max(dp[i+1][j],dp[i+1][j-1]);
      if(j>=w&&j-w<=s) {
        dp[i+1][j]=max(dp[i+1][j],dp[i][j-w]+v);
      }
    }
  }
  cout << dp[n][2e4] << endl;
}