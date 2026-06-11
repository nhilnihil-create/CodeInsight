#include <bits/stdc++.h>
using namespace std;
const int N = 10;

int main()
{
  int H, W;
  cin >> H >> W;
  vector<vector<int>> c(N, vector<int>(N));
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cin >> c.at(i).at(j);
    }
  }
  for (int k = 0; k < N; k++)
  {
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
      {
        c.at(i).at(j) = min(c.at(i).at(j), c.at(i).at(k) + c.at(k).at(j));
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      int a;
      cin >> a;
      if (a == -1)
      {
        continue;
      }
      else
      {
        ans += c.at(a).at(1);
      }
    }
  }
  cout << ans << endl;
}