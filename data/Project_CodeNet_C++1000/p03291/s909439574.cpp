#include <iostream>
#include <string>
#include <queue>
#include <utility>
#include <algorithm>
#include <numeric>
#include <set>
#include <climits>
#include <map>

using namespace std;

long long dp[100000][3];
const long long MOD = 1000000007;

int main(){
  string S;
  cin >> S;
  int N = S.size();

  if(S[0] == 'A' || S[0] == '?'){
    dp[0][0] = 1;
  }

  long long case_num = 1;
  for(int i = 0; i < N; i++){
    if(S[i] != '?'){
      for(int j = 0; j < 3; j++){
        dp[i][j] = dp[i - 1][j];
      }
      if(S[i] == 'A'){
        dp[i][0] = (dp[i][0] + case_num) % MOD;
      }
      if(S[i] == 'B'){
        dp[i][1] = (dp[i][1] + dp[i - 1][0]) % MOD;
      }
      if(S[i] == 'C'){
        dp[i][2] = (dp[i][2] + dp[i - 1][1]) % MOD;
      }
    } else {
      dp[i][0] = (dp[i - 1][0] * (long long) 3 + case_num) % MOD;
      dp[i][1] = (dp[i - 1][1] * (long long) 3 + dp[i - 1][0]) % MOD;
      dp[i][2] = (dp[i - 1][2] * (long long ) 3 + dp[i - 1][1]) % MOD;

      case_num = (case_num * 3) % MOD;
    }
  }

  cout << dp[N - 1][2] << endl;
  /*
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < N; j++){
      cout << dp[j][i] << " ";
    }
    cout << endl;
  }
  */
  return 0;
}
