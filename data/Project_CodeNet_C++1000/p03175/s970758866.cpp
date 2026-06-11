#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
 
using namespace std;
 
constexpr int MOD = 1e9 + 7;
 
vector<vector<int>> tree;
vector<vector<int>> dp;
 
size_t solution(int v, int p, bool black)
{ 
  if (dp[v][black] != -1)
  { 
    return dp[v][black];
  }
  auto& nodes = tree[v];
  size_t res = 1;
  for (auto n : nodes)
  { 
    if (n == p) continue;
    if (black)
    { 
      res *= solution(n, v, !black);
      res %= MOD;
    }
    else
    { 
      res = (res * (solution(n, v, !black) + solution(n, v, black))) % MOD;
    }
  }
  dp[v][black] = res;
  return res;
}
 
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
 
  int N;
  cin >> N;
 
  tree = vector<vector<int>>(N+1);
  dp = vector<vector<int>>(N+1, vector<int>(2, -1));
 
  for (int i = 0; i < N-1; ++i)
  {
    int x, y;
    cin >> x >> y;
    tree[x].push_back(y);
    tree[y].push_back(x);
  }
 
  cout << (solution(1, 0, true) + solution(1, 0, false)) % MOD << endl;
 
  return 0;
}