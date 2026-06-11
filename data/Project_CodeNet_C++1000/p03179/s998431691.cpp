#include<bits/stdc++.h>
using namespace std;

const int nex =  3010;
const int mod = 1e9 + 7;

char s[nex];
int dp[nex][nex];
// prefix sum array
int prefix_sum[nex][nex];
// dp[i][j] will store the numbers of ways we can arrange prefix of length i 
// whose last number is j

void add_self(int& a, int b)
{
  a += b;
  if(a > mod)
  {
    a -= mod;
  }
}

int main()
{
  int n;
  scanf("%d%s", &n, s);
  
  // now of ways to put number in string of length 1 is 1
  dp[1][1] = 1;
  
  for(int len = 2; len <= n; len++)
  {
    for(int i = 1; i <= len - 1; i++)
    {
      prefix_sum[len - 1][i] = (prefix_sum[len - 1][i - 1] + dp[len - 1][i]) % mod;
    }
    for(int last_place = 1; last_place <= len; last_place++)
    {
      int L, R;
      if(s[len - 2] == '<')
      {
        L = 1; 
        R = last_place - 1;
      }
      else
      {
        L = last_place;
        R = len - 1;
      }
      if(L <= R)
      {
        add_self(dp[len][last_place], (prefix_sum[len - 1][R] - prefix_sum[len - 1][L - 1] + mod) % mod);
      }
      //  for(int i = L; i <= R; i++)
      //  {
        //  add_self(dp[len][last_place], dp[len - 1][i]);
      //  }
      //  for(int second_last_place = 1; second_last_place <= len - 1; second_last_place++)
      //  {
        //  int real_at_second_last = second_last_place;
        //  if(real_at_second_last >= last_place)
        //  {
          //  real_at_second_last++;
        //  }
        //  if((real_at_second_last < last_place) != (s[len - 2] == '<'))
        //  {
          //  continue;
        //  }
        //  add_self(dp[len][last_place], dp[len - 1][second_last_place]);
      //  }
    }
  }
  int sol = 0;
  for(int i = 1; i <= n; i++)
  {
    add_self(sol, dp[n][i]);
  }
  printf("%d", sol);
  
  return 0;
}
