#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

struct edge
{
  int to;
  int cap;
  int rev;
};

std::vector<edge> edges[202];
int level[202];
int iter[202];

void add_edge(int from, int to, int cap)
{
  edges[from].emplace_back(edge{to, cap, edges[to].size()});
  edges[to].emplace_back(edge{from, 0, edges[from].size() - 1});
}

void bfs(int from)
{
  std::memset(level, -1, sizeof(level));
  std::queue<int>  q;
  level[from] = 0;
  q.push(from);
  while (q.size() > 0)
  {
    int v = q.front(); q.pop();
    for (auto& e : edges[v])
    {
      if (e.cap > 0 && level[e.to] < 0)
      {
        level[e.to] = level[v] + 1;
        q.push(e.to);
      }
    }
  }
}

int dfs(int v, int to, int f)
{
  if (v == to) return f;
  for (int &i = iter[v]; i < edges[v].size(); ++i)
  {
    edge& e = edges[v][i];
    if (e.cap > 0 && level[v] < level[e.to])
    {
      int d = dfs(e.to, to, std::min(f, e.cap));
      if (d > 0)
      {
        e.cap -= d;
        edges[e.to][e.rev].cap += d;
        return d;
      }
    }
  }
  return 0;
}

int max_flow(int from, int to)
{
  int flow = 0;
  while (true)
  {
    bfs(from);
    if (level[to] < 0) break;
    std::memset(iter, 0, sizeof(iter));
    int f;
    while ((f = dfs(from, to, 1e9)) > 0)
    {
      flow += f;
    }
  }
  return flow;
}

int redx[100], redy[100];
int bluex[100], bluey[100];

int main()
{
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
  {
    scanf("%d%d", redx + i, redy + i);
  }
  for (int i = 0; i < n; ++i)
  {
    scanf("%d%d", bluex + i, bluey + i);
  }
  for (int i = 0; i < n; ++i)
  {
    add_edge(2 * n, i, 1);
    add_edge(n + i, 2 * n + 1, 1);
    for (int j = 0; j < n; ++j)
    {
      if (redx[i] < bluex[j] && redy[i] < bluey[j])
      {
        add_edge(i, j + n, 1);
      }
    }
  }
  int ans = max_flow(2 * n, 2 * n + 1);
  printf("%d\n", ans);
  return 0;
}
