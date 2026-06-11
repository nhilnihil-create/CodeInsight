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
  string s;
  cin >> s;
  ll n=s.size();
  mat dp(n+1,vec(4));
  dp[n][3]=1;
  for(ll i=n-1;i>-1;i--) {
    for(ll j=3;j>-1;j--) {
      ll m=1;
      if(s[i]=='?') m=3;
      (dp[i][j]=m*dp[i+1][j])%=mod;
      if(s[i]=='?'||(j==0&&s[i]=='A')||(j==1&&s[i]=='B')||(j==2&&s[i]=='C')) m=1;
      else m=0;
      if(j!=3) {
        (dp[i][j]+=m*dp[i+1][j+1])%=mod;
      }
    }
  }
  cout << dp[0][0] << endl;
}