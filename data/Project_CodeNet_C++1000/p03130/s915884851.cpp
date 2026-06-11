#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define ll long long int

using namespace std;
int m[4][4] = {};

bool flag[4] = {};

// 連結かどうか
bool dfs(int j)
{
  flag[j] = true;
  REP(i, 4)
  {
    if (!flag[i] && m[i][j] == 1)
    {
      dfs(i);
    }
  }
}

int main()
{
  REP(i, 3)
  {
    int a, b;
    cin >> a >> b;
    m[a - 1][b - 1] = 1;
    m[b - 1][a - 1] = 1;
  }

  dfs(0);
  bool connected = flag[0] && flag[1] && flag[2] && flag[3];

  int edge[4] = {};
  // 各頂点から出る辺が(2,2,1,1)になっているかどうか
  REP(i, 4)
  {
    REP(j, 4)
    {
      edge[i] += m[i][j];
    }
  }
  sort(edge, edge + 4);
  bool ok = connected && edge[0] == 1 && edge[1] == 1 && edge[2] == 2 && edge[3] == 2;

  if (ok)
  {
    cout << "YES" << endl;
  }
  else
  {
    cout << "NO" << endl;
  }
}