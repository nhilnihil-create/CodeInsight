#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
// typedef pair<int,int> pp;
const int INF = 1e9;
const int MOD = 1000000007;

string S;
string ABC = "ABC";

int main() {
  cin >> S;
  int N = S.size();

  ll dp[100010][4] = {};
  for(int i = N; i >= 0; --i){
      for(int j = 3; j >= 0; --j){
          if(i == N){
              dp[i][j] = (j == 3 ? 1 : 0);
          }else{
              dp[i][j] = dp[i+1][j] * (S[i] == '?' ? 3LL : 1LL);
              if(j < 3 && (S[i] == '?' || S[i] == ABC[j])){
                  dp[i][j] += dp[i+1][j+1];
              }
              dp[i][j] %= MOD;
          }
      }
  }
  cout << dp[0][0] << endl;
}
