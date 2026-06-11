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
  string s;
  cin >> n >> s;
  mat dp(n+1,vec(n+1));
  for(ll i=0;i<n;i++) dp[0][i]=1;
  for(ll i=0;i<n;i++) {
    vec sum(n+10);
    for(ll j=0;j<n-i;j++) {
      sum[j+1]=(sum[j]+dp[i][j])%mod;
    }
    if(s[i]=='<') {
      for(ll j=0;j<n-i;j++) {
        dp[i+1][j]=(sum[n-i]-sum[j+1]+mod)%mod;
      }
    }
    else {
      for(ll j=0;j<n-i;j++) {
        dp[i+1][j]=sum[j+1];
      }
    }
  }
  cout << dp[n-1][0] << endl;
}