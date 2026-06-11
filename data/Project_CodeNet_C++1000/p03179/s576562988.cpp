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
  mat dp(n+1,vec(n+1));
  for(ll i=0;i<n;i++) dp[0][i]=1;
  for(ll i=0;i<n-1;i++) {
    vec sum(3010);
    for(ll j=0;j<n-i;j++) {
      sum[j+1]=(sum[j]+dp[i][j])%mod;
    }
    for(ll j=0;j<n-i;j++) {
      if(s[i]=='>') {
        dp[i+1][j]=sum[j+1];
      }
      else {
        dp[i+1][j]=(sum[n-i]-sum[j+1]+mod)%mod;
      }
    }
  }
  cout << dp[n-1][0] << endl;
}