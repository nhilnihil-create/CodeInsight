#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N;
  cin >> N;
  bool f;
  vector<int64_t> Open(N);
  vector<vector<int64_t>> Profit(N, vector<int64_t>(11));
  for (int i = 0; i < N; i++)
  {
    int64_t fbit = 0b0000000000;
    for (int j = 0; j < 10; j++)
    {
      cin >> f;
      if (f)
        fbit |= (1 << j);
    }
    Open.at(i) = fbit;
  }
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j <= 10; j++)
    {
      cin >> Profit.at(i).at(j);
    }
  }
  int64_t bit = 0b0000000001, maxProfit = -10000000000;
  ;
  while (bit <= 0b1111111111)
  {
    int64_t profit = 0;
    for (int i = 0; i < N; i++)
    {
      int64_t fbit = Open.at(i);
      int64_t cnt = __builtin_popcount(bit & fbit);
      profit += Profit.at(i).at(cnt);
    }
    maxProfit = max(profit, maxProfit);
    bit++;
  }
  cout << maxProfit << endl;
}