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
  string s;
  cin >> s;
  vector<int> dp(1<<26,1e9);
  dp[0]=0;
  ll x=0;
  for(char c:s) {
    x^=1<<(c-'a');
    for(ll i=0;i<26;i++) dp[x]=min(dp[x],dp[x^(1<<i)]+1);
  }
  cout << max(1,dp[x]) << endl;
}