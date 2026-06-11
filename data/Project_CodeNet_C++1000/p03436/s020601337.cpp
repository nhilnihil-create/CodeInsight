#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>
using namespace std;

using ll = long long;
using ld = long double;
const int INF = 1e9;
const double EPS = 1e-9;
const ll MOD = 1e9 + 7;

int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

int main()
{
  int H, W;
  cin >> H >> W;
  vector<string> s(H);
  for (auto &&i : s)
  {
    cin >> i;
  }
  queue<pair<int, int>> q;
  q.emplace(0, 0);
  vector<vector<int>> cost(H, vector<int>(W, INF));
  cost[0][0] = 1;
  while (!q.empty())
  {
    auto p = q.front();
    q.pop();
    int y = p.first, x = p.second;
    if (y == H - 1 && x == W - 1)
      break;
    for (int i = 0; i < 4; ++i)
    {
      int ny = y + dy[i], nx = x + dx[i];
      if (0 <= ny && ny < H && 0 <= nx && nx < W && s[ny][nx] == '.' && cost[ny][nx] == INF)
      {
        q.emplace(ny, nx);
        cost[ny][nx] = cost[y][x] + 1;
      }
    }
  }
  int cnt = 0;
  for (int i = 0; i < H; ++i)
  {
    for (int j = 0; j < W; ++j)
    {
      if (s[i][j] == '.')
        cnt++;
    }
  }
  if (cost[H - 1][W - 1] == INF)
    cout << -1 << endl;
  else
    cout << cnt - cost[H - 1][W - 1] << endl;

  return 0;
}
