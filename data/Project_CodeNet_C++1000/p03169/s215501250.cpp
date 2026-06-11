#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const long long int INF = 1LL<<60;
const long long int mod = 1e9 + 7;

double solve(vector<vector<vector<double>>> &dp, int i, int j, int k) {
  if(dp[i][j][k] >= 0) return dp[i][j][k];

  int N = dp.size() - 1;

  double res = 0.0;
  if (i > 0) res += solve(dp, i-1, j, k) * i;
  if (j > 0) res += solve(dp, i+1, j-1, k) * j;
  if (k > 0) res += solve(dp, i, j+1, k-1) * k;
  res += (double)N;
  res = res / (double)(i + j + k);

  return dp[i][j][k] = res;
}

int main() {
  int N;
  cin >> N;
  int one=0, two=0, three=0;
  for(int i=0; i<N; i++) {
    int a;
    cin >> a;
    if(a == 1) one++;
    else if(a == 2) two++;
    else three++;
  }

  vector<vector<vector<double>>> dp(N+1, vector<vector<double>>(N+1, vector<double>(N+1, -1)));
  dp[0][0][0] = 0.0;

  double res = solve(dp, one, two, three);
  printf("%.10f\n", res);

  return 0;
}