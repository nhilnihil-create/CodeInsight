#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
const bool WHITE = false;
const bool BLACK = true;

vector<int> dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};

int main()
{
  int H, W;
  cin >> H >> W;
  vector<vector<bool>> field(H, vector<bool>(W, WHITE));
  queue<pair<int, int>> que;
  rep(y, H)
  {
    rep(x, W)
    {
      char c;
      cin >> c;
      if (c == '#')
      {
        field.at(y).at(x) = BLACK;
        que.push(make_pair(y, x));
      }
    }
  }
  int ans = 0;
  while (!que.empty())
  {
    for (int i = que.size() - 1; i >= 0; i--)
    {
      int y, x;
      tie(y, x) = que.front();
      que.pop();
      rep(direction, 4)
      {
        int ny = y + dy.at(direction), nx = x + dx.at(direction);
        if (0 <= ny && ny < H && 0 <= nx && nx < W && field.at(ny).at(nx) == WHITE)
        {
          field.at(ny).at(nx) = BLACK;
          que.push(make_pair(ny, nx));
        }
      }
    }
    ans++;
  }
  cout << --ans << endl;
}