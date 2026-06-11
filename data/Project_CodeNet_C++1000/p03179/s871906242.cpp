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
  for(ll i=0;i<=n;i++) {
    dp[0][i]=1;
  }
  for(ll i=0;i<n;i++) {
    vec a(n+2);
    for(ll j=0;j<n-i;j++) {
      a[j+1]=(a[j]+dp[i][j])%mod;
    }
    for(ll j=0;j<n-i;j++) {
      if(s[i]=='<') {
        dp[i+1][j]=(a[n-i]-a[j+1]+mod)%mod;
      }
      else {
        dp[i+1][j]=a[j+1];
      }
    }
  }
  cout << dp[n][0] << endl;
}