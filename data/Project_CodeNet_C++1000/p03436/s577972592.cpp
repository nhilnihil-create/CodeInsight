#include <iostream>

#include <queue>
#include <string>
#include <tuple>

#include <cstring>

using std::cin;
using std::cout;
using std::endl;

using std::get;
using std::make_tuple;
using std::queue;
using std::string;
using std::tuple;

using std::memcpy;

using i3 = tuple<int, int, int>;

static int
distance(int H, int W, char mat[50][50])
{
  static int const dydx[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  char v[50][50];
  memcpy(v, mat, sizeof(v));
  queue<i3> q;
  q.push(make_tuple(0, 0, 0));
  while (!q.empty())
  {
    int y = get<0>(q.front());
    int x = get<1>(q.front());
    int d = get<2>(q.front());
    q.pop();
    if (y == H - 1 && x == W - 1)
    {
      return d;
    }
    for (int i = 0; i < 4; i++)
    {
      int yy = y + dydx[i][0];
      int xx = x + dydx[i][1];
      if (0 <= yy && yy < H && 0 <= xx && xx < W && v[yy][xx] != '#')
      {
        v[yy][xx] = '#';
        q.push(make_tuple(yy, xx, d + 1));
      }
    }
  }
  return -1;
}

static int
count_white(int H, int W, char mat[50][50])
{
  int ret = 0;
  for (int y = 0; y < H; y++)
  {
    for (int x = 0; x < W; x++)
    {
      if (mat[y][x] == '.')
      {
        ret++;
      }
    }
  }
  if (mat[0][0] == '.')
  {
    ret--;
  }
  if (mat[H - 1][W - 1] == '.')
  {
    ret--;
  }
  return ret;
}

static int
solve(int H, int W, char mat[50][50])
{
  int white = count_white(H, W, mat);
  int d = distance(H, W, mat);
  return d == -1 ? -1 : white - (d - 1);
}

int
main()
{
  int H, W;
  cin >> H >> W;
  char mat[50][50];
  string s;
  for (int y = 0; y < H; y++)
  {
    cin >> s;
    memcpy(mat[y], s.data(), s.size());
  }
  cout << solve(H, W, mat) << endl;
  return 0;
}
