#include <bits/stdc++.h>
using namespace std;
const int64_t MAXH = 510, MAXW = 510;
int64_t Grid[MAXH][MAXW];

int main()
{
  int64_t H, W;
  cin >> H >> W;
  for (int h = 0; h < H; h++)
  {
    for (int w = 0; w < W; w++)
    {
      cin >> Grid[h][w];
    }
  }
  queue<tuple<int, int, int, int>> ans;
  for (int h = 0; h < H; h++)
  {
    for (int w = 0; w < W; w++)
    {
      int64_t c = Grid[h][w];
      if (c % 2 == 0) // 偶数の場合はスキップ
        continue;
      if (h == H - 1 && w == W - 1) // 最後のマスはスキップ
        continue;
      if (h == H - 1 || Grid[h][w + 1] % 2)
      {
        Grid[h][w]--;
        Grid[h][w + 1]++; // 右に動かす
        ans.push(make_tuple(h + 1, w + 1, h + 1, w + 2));
      }
      else
      {
        Grid[h][w]--;
        Grid[h + 1][w]++; // 下に動かす
        ans.push(make_tuple(h + 1, w + 1, h + 2, w + 1));
      }
    }
  }
  cout << ans.size() << endl;
  int64_t a, b, c, d;
  while (!ans.empty())
  {
    tie(a, b, c, d) = ans.front();
    ans.pop();
    cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
  }
}