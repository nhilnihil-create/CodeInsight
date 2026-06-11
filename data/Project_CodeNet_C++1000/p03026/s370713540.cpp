#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, e) for (int i = (int)(s); i <= (int)(e); i++)
#define printYesNo(is_ok) puts(is_ok ? "Yes" : "No");
#define SORT(v) sort(v.begin(), v.end());
#define RSORT(v) sort(v.rbegin(), v.rend());
#define REVERSE(v) reverse(v.begin(), v.end());

template <typename T>
void printlnVector(T v)
{
  rep(i, v.size())
  {
    cout << v[i] << endl;
  }
}

template <typename T>
void printVector(T v)
{
  rep(i, v.size())
  {
    cout << v[i] << " ";
  }
  cout << endl;
}

int main()
{
  int N;
  cin >> N;
  vector<pair<int, int>> edge(N - 1);
  vector<int> edge_count(N), d(N), c(N);
  vector<set<int>> edges(N);
  rep(i, N - 1)
  {
    int a, b;
    cin >> a >> b;
    edge_count[--a]++;
    edge_count[--b]++;
    edges[a].insert(b);
    edges[b].insert(a);
    edge[i] = make_pair(a, b);
  }

  vector<set<int>> node(N + 10);
  rep(i, N)
  {
    node[edge_count[i]].insert(i);
    cin >> c[i];
  }
  SORT(c);

  int count = 0;
  while (node[1].size())
  {
    for (int edge_node : node[1])
    {
      int next_node = *edges[edge_node].begin();

      edges[next_node].erase(edge_node);
      edges[edge_node].erase(next_node);

      node[edge_count[next_node]].erase(next_node);
      node[edge_count[next_node] - 1].insert(next_node);

      edge_count[next_node]--;
      edge_count[edge_node]--;

      node[1].erase(edge_node);

      d[edge_node] = c[count++];
    }
  }
  rep(i, N)
  {
    if (d[i] == 0)
      d[i] = c.back();
  }

  long long M = 0;
  rep(i, N - 1)
  {
    M += min(d[edge[i].first], d[edge[i].second]);
  }
  cout << M << endl;
  printVector(d);
  return 0;
}