#include <bits/stdc++.h>
using namespace std;
const int INF = (1 << 30);
int H, W;
bool Grid[55][55];
int path[55][55];

void init()
{
  for (int i = 0; i < 55; i++)
  {
    for (int j = 0; j < 55; j++)
    {
      path[i][j] = INF;
    }
  }
}

int main()
{
  int cnt = 0;
  cin >> H >> W;
  char c;
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      cin >> c;
      Grid[i][j] = (c == '.');
      if (c == '#')
        cnt++;
    }
  }
  init();
  queue<pair<int, int>> Q;
  Q.emplace(0, 0);
  path[0][0] = 1;
  int dh[] = {1, 0, 0, -1};
  int dw[] = {0, -1, 1, 0};
  while (Q.size())
  {
    auto p = Q.front();
    Q.pop();
    for (int i = 0; i < 4; i++)
    {
      int nexth = p.first + dh[i], nextw = p.second + dw[i];
      if (nexth < 0 || nexth >= H || nextw < 0 || nextw >= W)
      {
        continue;
      }
      if (Grid[nexth][nextw] && path[nexth][nextw] > path[p.first][p.second] + 1)
      {
        path[nexth][nextw] = path[p.first][p.second] + 1;
        Q.emplace(nexth, nextw);
      }
    }
  }
  if (path[H - 1][W - 1] == INF)
  {
    cout << -1 << endl;
  }
  else
  {
    int ans = H * W - path[H - 1][W - 1] - cnt;
    cout << ans << endl;
  }
}
