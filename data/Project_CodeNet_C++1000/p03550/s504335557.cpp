#include <bits/stdc++.h>
using namespace std;
int64_t N, Z, W;
const int MAXN = 2010;
const int64_t INF = (1LL << 62);
vector<int64_t> A(MAXN);
vector<vector<int64_t>> DP(2, vector<int64_t>(MAXN, -1)); // turn/topの時の最大値

int64_t dfs(int64_t turn, int64_t top, int64_t x, int64_t y) // x: turn = 0, y: turn = 1
{
  if (top == N)
  {
    return abs(x - y);
  }
  if (DP[turn][top] != -1)
  {
    return DP[turn][top];
  }
  if (turn) // y
  {
    int64_t ret = INF;
    for (int i = top; i < N; i++) // i番目のカードまで取る
    {
      ret = min(ret, dfs(!turn, i + 1, x, A.at(i)));
    }
    return DP[turn][top] = ret;
  }
  else // x
  {
    int64_t ret = 0;
    for (int i = top; i < N; i++) // i番目のカードまで取る
    {
      ret = max(ret, dfs(!turn, i + 1, A.at(i), y));
    }
    return DP[turn][top] = ret;
  }
}

int main()
{
  cin >> N >> Z >> W;
  for (int i = 0; i < N; i++)
  {
    cin >> A[i];
  }
  cout << dfs(0, 0, Z, W) << endl;
}