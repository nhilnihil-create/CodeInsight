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

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int main()
{
  long long H;
  scanf("%lld", &H);
  long long W;
  scanf("%lld", &W);
  std::vector<std::string> A(H);
  for (int i = 0; i < H; i++)
  {
    std::cin >> A[i];
  }
  queue<pair<int, int>> q;
  int seen[1001][1001] = {};
  for (int i = 0; i < H; ++i)
  {
    for (int j = 0; j < W; ++j)
    {
      seen[i][j] = INF;
      if (A[i][j] == '#')
      {
        q.emplace(j, i);
        seen[i][j] = 0;
      }
    }
  }
  int ans = 0;
  while (!q.empty())
  {
    auto p = q.front();
    q.pop();
    for (int i = 0; i < 4; ++i)
    {
      int x = p.first, y = p.second;
      int nx = x + dx[i], ny = y + dy[i];
      if (0 <= nx && nx < W && 0 <= ny && ny < H && seen[ny][nx] == INF)
      {
        q.emplace(nx, ny);
        seen[ny][nx] = seen[y][x] + 1;
        ans = seen[ny][nx];
      }
    }
  }
  cout << ans << endl;

  return 0;
}
