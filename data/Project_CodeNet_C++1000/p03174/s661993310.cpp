#include <iostream>

using namespace std;

typedef long long int ll;

const unsigned int TWO = 2097153, N = 22, MOD = 1e9 + 7;

unsigned int dp[N][TWO];
int n, compatible[N][N];

unsigned int countWays(int currMan, ll usedWomen, int menCount, int womenCount) {
  if (menCount == n && womenCount == n)
    return 1;
  if (menCount == n || womenCount == n)
    return 0;

  if (dp[currMan][usedWomen] != -1)
    return dp[currMan][usedWomen];

  dp[currMan][usedWomen] = 0;

  for (int i = 0; i < n; i++)
    if (compatible[currMan][i] && !(usedWomen & (1 << i)))
      dp[currMan][usedWomen] += countWays(currMan+1, usedWomen | (1 << i), menCount+1, womenCount+1) % MOD, dp[currMan][usedWomen] %= MOD;

  dp[currMan][usedWomen] %= MOD;
  return dp[currMan][usedWomen];
}

int main() {
  cin >> n;
  
  for (int i = 0; i < N; i++)
    for (int j = 0; j < TWO; j++)
      dp[i][j] = -1;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> compatible[i][j];

  cout << countWays(0, 0, 0, 0) % MOD << endl;
}
