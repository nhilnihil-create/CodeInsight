#include <cstdio>
#include <algorithm>
#include <queue>
#include <utility>
#include <functional>

struct edge
{
  int to;
  int cost;
};

edge edges[100000][2];
int dist[100000];

int main()
{
  int k;
  scanf("%d", &k);
  for (int i = 0; i < k; ++i)
  {
    edges[i][0] = edge{(i * 10) % k, 0};
    edges[i][1] = edge{(i + 1) % k, 1};
  }
  std::fill(dist, dist + k, (int)1e9);
  dist[1] = 0;
  using pair = std::pair<int, int>;
  std::priority_queue<pair, std::vector<pair>, std::greater<pair>> q;
  q.emplace(pair{0, 1});
  while (q.size() > 0)
  {
    auto p = q.top(); q.pop();
    if (p.first > dist[p.second]) continue;
    for (auto &e : edges[p.second])
    {
      int nc = e.cost + dist[p.second];
      if (nc < dist[e.to])
      {
        dist[e.to] = nc;
        q.emplace(pair{nc, e.to});
      }
    }
  }
  printf("%d\n", dist[0] + 1);
  return 0;
}
