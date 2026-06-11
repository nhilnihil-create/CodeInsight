#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

int dp[101][100001];

int findTotalWays(int childs, int candies, vector < int > &maxCandies) {
  memset(dp, -1, sizeof(dp));
  for (int i = 0; i < childs + 1; i++) {
    dp[i][0] = 1;
  }
  for (int j = 1; j < candies + 1; j++) {
    dp[0][j] = 0;
  }

  vector < int > sum(candies + 2, 0);

  for (int i = 1; i < childs + 1; i++ ) {
    sum[0] = 0;
    for (int j = 1; j <= candies + 1; j++) {
      sum[j] = ((sum[j - 1] % mod) + (dp[i - 1][j - 1] % mod)) % mod;
    }
    for (int j = 1; j < candies + 1; j++) {
      if (j - maxCandies[i - 1] < 0) {
        dp[i][j] = (sum[j + 1] - sum[0] + mod) % mod;
      } else {
        dp[i][j] = (sum[j + 1] - sum[j - maxCandies[i - 1]] + mod) % mod;
      }
    }
  }

  return dp[childs][candies];
}

int main() {
  int childs;
  int candies;
  cin>>childs;
  cin>>candies;
  vector < int > maxCandies;
  int maxCandy;
  for (int i = 0; i < childs; i++) {
    cin>>maxCandy;
    maxCandies.push_back(maxCandy);
  }
  cout<<findTotalWays(childs, candies, maxCandies)<<endl;
  return 0;
}
