#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
constexpr int mod = 1e9 + 7;
 
int main(){ 
  string s;
  cin >> s;
  int n = s.size();
 
  vector<ll> dp(5, 0);
 
  dp[0] = 1;
 
  for (int i = 0; i < n; i++) {
    vector<ll> ndp(5, 0);
 
    for (int j = 0; j < 4; j++) {
      if (s[i] == '?') (ndp[j] += dp[j] * 3 % mod) %= mod; 
      else (ndp[j] += dp[j]) %= mod;
    }
    
    if (s[i] == '?' || s[i] == 'A') (ndp[1] += dp[0]) %= mod;
    if (s[i] == '?' || s[i] == 'B') (ndp[2] += dp[1]) %= mod;
    if (s[i] == '?' || s[i] == 'C') (ndp[3] += dp[2]) %= mod;
    swap(dp, ndp);
  }
 
  cout << dp[3] << endl;
  return 0;
} 