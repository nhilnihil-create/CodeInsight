#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#define ll long long
using namespace std;

ll N, M;
vector<int> A, B;
vector<vector<int>> G;
vector<int> color;
bool bipartite = true;

void dfs(int v, int cur = 0)
{
  color[v] = cur;
  for (int next_v : G[v])
  {
    if (color[next_v] == cur)
    {
      bipartite = false;
      continue;
    }
    if (color[next_v] == -1)
    {
      color[next_v] = 1 - cur;
      dfs(next_v, 1 - cur);
      continue;
    }
  }
}

int main()
{
  cin >> N >> M;
  A.resize(M);
  B.resize(M);
  for (int i = 0; i < M; i++)
  {
    cin >> A[i] >> B[i];
    A[i]--;
    B[i]--;
  }

  G.assign(N, {});
  for (int i = 0; i < M; i++)
  {
    G[A[i]].push_back(B[i]);
    G[B[i]].push_back(A[i]);
  }

  color.resize(N, -1);

  dfs(0);

  ll color_0 = 0, color_1 = 0;
  for (int i = 0; i < N; i++)
  {
    if (color[i] == 0)
    {
      color_0++;
    }
    else if (color[i] == 1)
    {
      color_1++;
    }
    else
    {
      cout << "SWW" << endl;
    }
  }

  if (bipartite)
  {
    cout << color_0 * color_1 - M << endl;
  }
  else
  {
    cout << N * (N - 1) / 2 - M << endl;
  }
}