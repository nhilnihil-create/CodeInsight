#include <bits/stdc++.h>
using namespace std;
bool dp[100010];

int main()
{
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A.at(i);
  }
  for (int i = 1; i <= K; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (i - A.at(j) >= 0)
      {
        dp[i] |= !dp[i - A.at(j)];
      }
    }
  }
  cout << (dp[K] ? "First" : "Second") << endl;
}
