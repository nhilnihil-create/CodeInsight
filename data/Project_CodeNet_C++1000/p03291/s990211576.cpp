#include <iostream>
#include <string>
#include <cstring>

using namespace std;
string S;



long long dp[200100][5];

int main() {
  cin >> S;
  
  memset(dp, 0, sizeof(dp));
  
  dp[0][0] = 1;
  for (int i = 0; i < S.size(); ++i) {
	for (int j = 0; j < 5; ++j) {
      
	  if (S[i] != '?') dp[i+1][j] += dp[i][j]%1000000007 ;
      
	  else dp[i+1][j] += dp[i][j] * 3 % 1000000007;
	}
	if (S[i] == 'A' || S[i] == '?') dp[i+1][1] += dp[i][0]%1000000007;
	if (S[i] == 'B' || S[i] == '?') dp[i+1][2] += dp[i][1]%1000000007;
	if (S[i] == 'C' || S[i] == '?') dp[i+1][3] += dp[i][2]%1000000007;  
  }
  
  cout << dp[S.size()][3]%1000000007 << endl;
}
