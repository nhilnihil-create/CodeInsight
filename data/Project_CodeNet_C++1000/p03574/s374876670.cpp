#include <bits/stdc++.h>
using namespace std;

int main()
{
  int H, W;
  cin >> H >> W;
  char c;
  vector<vector<int>> G(H + 2, vector<int>(W + 2, 0));
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      cin >> c;
      if (c == '#')
        G[i + 1][j + 1] = 9;
    }
  }
  int dh[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
  int dw[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
  for (int i = 1; i <= H; i++)
  {
    for (int j = 1; j <= W; j++)
    {
      if (G[i][j] == 9)
      {
        cout << '#';
        continue;
      }
      int tmp = 0;
      for (int k = 0; k < 8; k++)
        tmp += (G[i + dh[k]][j + dw[k]] == 9);
      cout << tmp;
    }
    cout << endl;
  }
}