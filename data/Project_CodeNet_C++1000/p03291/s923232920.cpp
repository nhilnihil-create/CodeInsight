#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=5e15;
 
int main() {
  string s;
  cin >> s;
  ll n=s.size();
  string abc="ABC";
  mat dp(n+1,vec(4,0));
  dp[n][3]=1;
  for(ll i=n;i;i--) {
    for(ll j=3;j>-1;j--) {
      ll m=1;
      if(s[i-1]=='?') m=3;
      dp[i-1][j]=m*dp[i][j];
      if(j!=3&&(s[i-1]=='?'||s[i-1]==abc[j])) {
        dp[i-1][j]+=dp[i][j+1];
      }
      dp[i-1][j]%=mod;
    }
  }
  cout << dp[0][0] << endl;
}