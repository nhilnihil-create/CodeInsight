#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>

using namespace std;

int N;
size_t MASK;
vector<vector<int>> v;
vector<int> dp;

inline size_t add(size_t res, size_t delta)
{ 
  return (res + delta) % 1000000007;
}

size_t solution(int i, size_t mask = 0)
{ 
  if (dp[mask] != -1) return dp[mask];
  size_t res = 0; 
  for (int j = 0; j < N; ++j)
  { 
    if (v[i][j] && !(mask & (1<<j)))
    { 
      const size_t new_mask = mask | (1<<j);
      if (new_mask == MASK)
      { 
        res = add(res, 1);
        break;
      }
      res = add(res, solution(i+1, new_mask));
    }
  }
  dp[mask] = res;
  return res;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  cin >> N;

  MASK = (1 << N) - 1;

  v = vector<vector<int>>(N, vector<int>(N));
  dp = vector<int>(1<<N, -1);

  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j < N; ++j)
    {   
      cin >> v[i][j];
    }   
  }

  cout << solution(0);

  return 0;
}