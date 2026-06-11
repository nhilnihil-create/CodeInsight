#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;
constexpr ll mod = 1e9+7;

int main(){ 
  string s;
  cin >> s;
  int n = sz(s);
  vector<ll> dp(5,0);
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    vector<ll> next(5,0);
    for (int j = 0; j < 4; j++) {
      if (s[i] == '?') (next[j] += dp[j]*3%mod) %= mod; 
      else (next[j] += dp[j]) %= mod;
    }
    if (s[i] == 'A' || s[i] == '?') (next[1] += dp[0]) %= mod;
    if (s[i] == 'B' || s[i] == '?') (next[2] += dp[1]) %= mod;
    if (s[i] == 'C' || s[i] == '?') (next[3] += dp[2]) %= mod;
    dp = next;
  }
  cout << dp[3] << endl;
  return 0;
} 