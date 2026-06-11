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
  vec dp(1<<n);
  for(ll i=0;i<(1<<n);i++) {
    for(ll j=0;j<n;j++) {
      for(ll k=j+1;k<n;k++) {
        if((i>>j)&(i>>k)&1) {
          dp[i]+=a[j][k];
        }
      }
    }
    for(ll j=i;j>0;j=(j-1)&i) {
      dp[i]=max(dp[i],dp[j]+dp[i^j]);
    }
  }
  cout << dp[(1<<n)-1] << endl;
}