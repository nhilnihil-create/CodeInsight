#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

vector<int> dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};

int main()
{
  int H, W;
  cin >> H >> W;
  vector<vector<bool>> field(H, vector<bool>(W, false));
  int cnt = 0;
  rep(y, H)
  {
    rep(x, W)
    {
      char c;
      cin >> c;
      if (c == '.')
      {
        field.at(y).at(x) = true;
        cnt++;
      }
    }
  }

  vector<vector<int>> dist(H, vector<int>(W, -1));
  queue<pair<int, int>> que;
  dist.at(0).at(0) = 1;
  que.push(make_pair(0, 0));
  while (!que.empty())
  {
    int y, x;
    tie(y, x) = que.front();
    que.pop();
    rep(direction, 4)
    {
      int ny = y + dy.at(direction), nx = x + dx.at(direction);
      if (0 <= ny && ny < H && 0 <= nx && nx < W)
      {
        if (field.at(ny).at(nx))
        {
          if (dist.at(ny).at(nx) == -1)
          {
            dist.at(ny).at(nx) = dist.at(y).at(x) + 1;
            que.push(make_pair(ny, nx));
          }
        }
      }
    }
  }
  if (dist.at(H - 1).at(W - 1) == -1)
  {
    cout << -1 << endl;
  }
  else
  {
    cout << cnt - dist.at(H - 1).at(W - 1) << endl;
  }
}