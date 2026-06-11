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
      tmp += (G[i - 1][j - 1] == 9);
      tmp += (G[i - 1][j] == 9);
      tmp += (G[i - 1][j + 1] == 9);
      tmp += (G[i][j - 1] == 9);
      tmp += (G[i][j + 1] == 9);
      tmp += (G[i + 1][j - 1] == 9);
      tmp += (G[i + 1][j] == 9);
      tmp += (G[i + 1][j + 1] == 9);
      cout << tmp;
    }
    cout << endl;
  }
}