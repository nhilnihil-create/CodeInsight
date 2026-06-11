#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int N = 102;
const int MAXV = 1e5 + 2;
long long dp[N][MAXV], pref[MAXV];
// dp[i][j] = no. of ways to distribut total j candies until child i

signed main(){
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1);
  
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  
  dp[0][0] = 1;
  
  for(int i = 1; i <= n; i++){
    for(int j = 0; j <= k; j++){
        pref[j + 1] = (pref[j] + dp[i - 1][j]) % mod;
    }
    
    for(int j = 0; j <= k; j++){
        dp[i][j] = (pref[j + 1] - pref[max(0, j - a[i])] + mod) % mod;
    }
  }
  
  cout << dp[n][k];
  
  return 0;
}