#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
ll mod=1e9+7;

int main() {
  ll n;
  cin >> n;
  vec c(n);
  for(ll i=0;i<n;i++) {
    cin >> c[i];
  }
  vec dp(n+1);
  vec left(2e5+1,-1);
  dp[0]=1;
  for(ll i=0;i<n;i++) {
    dp[i+1]=dp[i];
    ll tc=c[i];
    if(left[tc]>-1&&left[tc]<i-1) dp[i+1]=(dp[i+1]+dp[left[tc]+1])%mod;
    left[tc]=i;
  }
  cout << dp[n] << endl;
}