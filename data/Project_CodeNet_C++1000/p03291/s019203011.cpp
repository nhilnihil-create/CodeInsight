#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <map>
#define rep(i, N) for (int i = 0; i < (int)N; i++)
using namespace std;
typedef long long ll;
const ll LLINF = 9223372036854775807;
const ll MOD = 1000000007;
const int S_MAX = pow(10,5);

string S;
vector<vector<int>> dp(S_MAX+1, vector<int>(4, -1));

ll dfs(int n, int abc) {
  if (dp[n][abc]!=-1) return dp[n][abc];
  if (n==0) return dp[n][abc] = abc==0 ? 1 : 0;
  ll result = dfs(n-1, abc);
  if (S[n-1]=='A') { if (abc==1) result += dfs(n-1,0); }
  if (S[n-1]=='B') { if (abc==2) result += dfs(n-1,1); }
  if (S[n-1]=='C') { if (abc==3) result += dfs(n-1,2); }
  if (S[n-1]=='?') { 
    if (abc!=0) result += dfs(n-1,abc-1);
    result += dfs(n-1, abc) * 2;
  }
  return dp[n][abc] = result % MOD;
}

int main() {
  cin >> S;
  dfs(S.length(), 3);
  // rep(i,S.length()+1) { rep(j,4) cout << dp[i][j] << " "; cout << endl; }
  cout << dp[S.length()][3] << endl;
  return 0;
}