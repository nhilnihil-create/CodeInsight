#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
vector<int> to[MAXN], from[MAXN];

int par[MAXN];
bool visited[MAXN];
void dfs(int u)
{
  visited[u] = 1;
  for (auto v : to[u])
  {
    if (visited[v])
      continue;
    bool ok = 1;
    for (auto w : from[v])
    {
      if (!visited[w])
      {
        ok = 0;
        break;
      }
    }
    if (ok)
    {
      par[v] = u;
      dfs(v);
    }
  }
}

int main()
{
  int N, M, a, b, root;
  cin >> N >> M;
  for (int i = 0; i < N + M - 1; i++)
  {
    cin >> a >> b;
    a, b;
    to[a].push_back(b);
    from[b].push_back(a);
  }
  for (int i = 1; i <= N; i++)
  {
    if (from[i].size() == 0)
      root = i;
  }
  par[root] = 0;
  dfs(root);
  for (int i = 1; i <= N; i++)
  {
    cout << par[i] << endl;
  }
}