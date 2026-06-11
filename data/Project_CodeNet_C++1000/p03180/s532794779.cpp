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
  cin >> n;
  mat a(n,vec(n));
  for(ll i=0;i<n;i++) for(ll j=0;j<n;j++) cin >> a[i][j];
  vec dp(1<<n);
  for(ll S=0;S<(1<<n);S++) {
    for(ll i=0;i<n;i++) {
      for(ll j=0;j<i;j++) {
        if(S>>i&S>>j&1) dp[S]+=a[i][j];
      }
    }
    for(ll T=S;T>0;T=T-1&S) {
      if(T==S) continue;
      dp[S]=max(dp[S],dp[T]+dp[S^T]);
    }
  }
  cout << dp[(1<<n)-1] << endl;
}