#include <bits/stdc++.h>

using namespace std;

#define INF 100000000
#define YJ 1145141919
#define INF_INT_MAX 2147483647
#define INF_LL_MAX 9223372036854775807
#define EPS 1e-10
#define Pi acos(-1)
#define LL long long
#define ULL unsigned long long
#define LD long double

const int MAX_S = 305;
string S;
int K;

int dp[MAX_S][MAX_S][MAX_S];

int main()
{
  cin >> S;
  cin >> K;
  
  memset(dp, 0, sizeof(dp));

  //配るdpだと偶数の時がバグるので貰うdpにする
  for(int w = 0; w < S.length(); w++) {
    for(int l = 0; l+w < S.length(); l++) {
      int r = l+w;
      for(int k = 0; k <= K; k++) {
	if(l == r) {
	  dp[l][r][k] = 1;
	} else { 
	  //何もしない
	  if(l+1 < S.length()) {
	    dp[l][r][k] = max(dp[l][r][k], dp[l+1][r][k]);
	  }
	  if(r-1 >= 0) {
	    dp[l][r][k] = max(dp[l][r][k], dp[l][r-1][k]);
	  }

	  //回文を伸ばす
	  if(l+1 < S.length() && r-1 >= 0) {
	    if(S[l] == S[r]) {
	      dp[l][r][k] = max(dp[l][r][k], dp[l+1][r-1][k] + 2);
	    }
	    if(k < K) {
	      dp[l][r][k] = max(dp[l][r][k], dp[l+1][r-1][k+1] + 2);
	    }
	  }
	}
      }
    }
  }

  int ans = 0;
  for(int k = 0; k <= K; k++) {
    ans = max(ans, dp[0][S.length()-1][k]);
  }

  cout << ans << endl;

  return 0;
}
