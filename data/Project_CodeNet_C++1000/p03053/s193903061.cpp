#include <iostream>

#include <algorithm>
#include <queue>
#include <string>
#include <tuple>

#include <cstring>

using std::cin;
using std::cout;
using std::endl;

using std::get;
using std::make_tuple;
using std::max;
using std::queue;
using std::string;
using std::tuple;

using std::memcpy;

using i3 = tuple<int, int, int>;

static int const dydx[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
static int H, W;
static char mat[1000][1000];

static int
solve()
{
  queue<i3> q;
  for (int y = 0; y < H; y++)
  {
    for (int x = 0; x < W; x++)
    {
      if (mat[y][x] == '#')
      {
        q.push(make_tuple(y, x, 0));
      }
    }
  }
  int ret = 0;
  while (!q.empty())
  {
    int y = get<0>(q.front());
    int x = get<1>(q.front());
    int d = get<2>(q.front());
    q.pop();
    for (int i = 0; i < 4; i++)
    {
      int yy = y + dydx[i][0];
      int xx = x + dydx[i][1];
      if (0 <= yy && yy < H && 0 <= xx && xx < W && mat[yy][xx] == '.')
      {
        mat[yy][xx] = '#';
        q.push(make_tuple(yy, xx, d + 1));
        ret = max(ret, d + 1);
      }
    }
  }
  return ret;
}

int
main()
{
  cin >> H >> W;
  string s;
  for (int y = 0; y < H; y++)
  {
    cin >> s;
    memcpy(mat[y], s.data(), W);
  }
  cout << solve() << endl;
  return 0;
}
