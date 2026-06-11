#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>
using namespace std;

using ll = long long;
using ld = long double;
const int INF = 1e9;
const double EPS = 1e-9;
const ll MOD = 1e9 + 7;

long long N;
vector<vector<vector<double>>> dp;
int cnt[4];

double dfs(int i, int j, int k)
{
  if (dp[i][j][k] != -1)
    return dp[i][j][k];
  if (i == 0 && j == 0 && k == 0)
    return 0.0;
  double ret = 0.0;
  if (i - 1 >= 0)
    ret += dfs(i - 1, j, k) * i;
  if (j - 1 >= 0)
    ret += dfs(i + 1, j - 1, k) * j;
  if (k - 1 >= 0)
    ret += dfs(i, j + 1, k - 1) * k;
  ret += N;
  ret /= (i + j + k);
  return dp[i][j][k] = ret;
}

int main()
{
  scanf("%lld", &N);
  std::vector<long long> a(N);
  for (int i = 0; i < N; i++)
  {
    scanf("%lld", &a[i]);
    cnt[a[i]]++;
  }
  dp.assign(301, vector<vector<double>>(301, vector<double>(301, -1)));
  dp[0][0][0] = 0.0;
  printf("%.10lf\n", dfs(cnt[1], cnt[2], cnt[3]));

  return 0;
}
