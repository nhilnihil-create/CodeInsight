#include<bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> V(N+1);
  int S = 0;
  for(int i = 1 ; i <= N ; i++)
  {
    cin >> V[i];
 	S += V[i];
  }
  bitset<2000009> dp;
  dp[0] = 1;
  for(int i = 0 ; i <= N ; i++)
  {
    dp = dp | (dp << V[i]);
  }
  int s;
  for(s = (S+1)/2 ; s <= S ; s++)
    if(dp[s] > 0)
      break;
  cout << s;
  return 0;
}