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
  ll n,k;
  cin >> n >> k;
  vec a(n);
  for(ll i=0;i<n;i++) cin >> a[i];
  mat dp(n+1,vec(k+1));
  dp[0][0]=1;
  for(ll i=0;i<n;i++) {
    vec s(k+1);
    s[0]=dp[i][0];
    for(ll j=0;j<k;j++) {
      s[j+1]=(s[j]+dp[i][j+1])%mod;
    }
    for(ll j=0;j<=k;j++) {
      dp[i+1][j]=s[j];
      if(j-a[i]>0) {
        dp[i+1][j]=(dp[i+1][j]-s[j-a[i]-1]+mod)%mod;
      }
    }
  }
  cout << dp[n][k] << endl;
}