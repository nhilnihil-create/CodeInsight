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



int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  cin >> N;

  MASK = (1<<N) - 1;

  v = vector<vector<int>>(N, vector<int>(N));
  dp = vector<int>(1<<N, 0);
  auto bc = dp;  // bits count

  for (int i = 0; i < N; ++i)
  { 
    for (int j = 0; j < N; ++j)
    { 
      cin >> v[i][j];
    }
  }
  
  dp[MASK] = 1;

  for (int i = 1; i < (1<<N); ++i)
  {   
    bc[i] = bc[i & (i-1)] + 1;
  }
  
  for (int i = N-1; i >= 0; --i)
  {
    for (int mask = 0; mask < MASK; ++mask)
    {   
      if (bc[mask] != i) continue;
      size_t res = 0;
      for (int j = 0; j < N; ++j)
      {   
        if (v[i][j] && !(mask & (1<<j)))
        {   
          const size_t new_mask = mask | (1<<j);
          res += dp[new_mask];
          res %= 1000000007;
        }   
      }   
      dp[mask] = res;
    }   
  }

  cout << dp[0];

  return 0;
}