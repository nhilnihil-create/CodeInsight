#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=5e15;

const ll N=1e5+10;
mat dp(N,vec(4));
ll n;
string s;

int main() {
  cin >> s;
  n=s.size();
  dp[n][3]=1;
  string abc="ABC";
  for(ll i=n;i;i--) {
    for(ll j=3;j>-1;j--) {
      if(j==3) {
        ll m=1;
        if(s[i-1]=='?') m=3;
        dp[i-1][j]=m*dp[i][j];
      }
      else {
        ll m=1;
        if(s[i-1]=='?') m=3;
        dp[i-1][j]=m*dp[i][j];
        m=0;
        if(s[i-1]=='?'||s[i-1]==abc[j]) m=1;
        dp[i-1][j]+=m*dp[i][j+1];
      }
      dp[i-1][j]%=mod;
    }
  }
  cout << dp[0][0] << endl;
}