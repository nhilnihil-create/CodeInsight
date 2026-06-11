#include <bits/stdc++.h>
using namespace std;
const int MAXN = 510;
const int MAXC = 40;
int64_t N, C, ans = (1LL << 62);
int cs[MAXN][MAXN];
int ds[MAXC][MAXC];
int memo[3][MAXC];

void init()
{
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < MAXC; j++)
      memo[i][j] = -1;
}

int64_t calc(int r, int c)
{
  int64_t s0 = 0, s1 = 0, s2 = 0;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if ((i + j) % 3 == 0)
        s0 += ds[cs[i][j]][c];
      else if ((i + j) % 3 == 1)
        s1 += ds[cs[i][j]][c];
      else
        s2 += ds[cs[i][j]][c];
    }
  }
  memo[0][c] = s0;
  memo[1][c] = s1;
  memo[2][c] = s2;
  return memo[r][c];
}

int main()
{
  cin >> N >> C;
  for (int i = 0; i < C; i++)
    for (int j = 0; j < C; j++)
      cin >> ds[i][j];
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cin >> cs[i][j];
      cs[i][j]--;
    }
  }
  init();
  for (int a = 0; a < C; a++)
  {
    for (int b = 0; b < C; b++)
    {
      for (int c = 0; c < C; c++)
      {
        if (a == b || b == c || c == a)
          continue;
        int64_t da = memo[0][a] == -1 ? calc(0, a) : memo[0][a];
        int64_t db = memo[1][b] == -1 ? calc(1, b) : memo[1][b];
        int64_t dc = memo[2][c] == -1 ? calc(2, c) : memo[2][c];
        ans = min(ans, da + db + dc);
      }
    }
  }
  cout << ans << endl;
}