#include <iostream>
#include <string>

using lli=long long;
lli mod=1000000007;

int main(){
  std::string S;
  std::cin >> S;

  lli dp[100004][4] = {};
  dp[0][0] = 1;

  for(int i = 0; i < S.size(); i++){
    char s = S[i];
    if(s == 'A' || s == '?'){
      (dp[i+1][0] += dp[i][0]) %= mod;
      (dp[i+1][1] += dp[i][1]+dp[i][0]) %= mod;
      (dp[i+1][2] += dp[i][2]) %= mod;
      (dp[i+1][3] += dp[i][3]) %= mod;
    }
    if(s == 'B' || s == '?'){
      (dp[i+1][0] += dp[i][0]) %= mod;
      (dp[i+1][1] += dp[i][1]) %= mod;
      (dp[i+1][2] += dp[i][2]+dp[i][1]) %= mod;
      (dp[i+1][3] += dp[i][3]) %= mod;
    }
    if(s == 'C' || s == '?'){
      (dp[i+1][0] += dp[i][0]) %= mod;
      (dp[i+1][1] += dp[i][1]) %= mod;
      (dp[i+1][2] += dp[i][2]) %= mod;
      (dp[i+1][3] += dp[i][3]+dp[i][2]) %= mod;
    }
  }
  std::cout << dp[S.size()][3] << std::endl;

  return 0;
}

