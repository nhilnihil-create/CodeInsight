#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define P pair<int, int>
#define fi first
#define se second
#define INF (1 << 30)
#define REP(i, n) for (int i = 0; i < n; i++)

const int MAX_V = 100000;
struct edge {
  int to, cost;
};
int V;
vector<edge> G[MAX_V];
int d[MAX_V];

void bfs01(int s) {
  deque<P> que;
  fill(d, d + V, INF);
  d[s] = 0;
  que.push_back(P(0, s));
  while (!que.empty()) {
    P p = que.front();
    que.pop_front();
    int v = p.se;
    if (d[v] < p.fi) continue;
    for (int i = 0; i < G[v].size(); i++) {
      edge e = G[v][i];
      if (d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost;
        if (e.cost == 0)
          que.push_front(P(d[e.to], e.to));
        else
          que.push_back(P(d[e.to], e.to));
      }
    }
  }
}

int main() {
  cin >> V;
  REP(i, V) {
    edge t;
    t.to = (i + 1) % V;
    t.cost = 1;
    G[i].pb(t);
  }
  REP(i, V) {
    edge t;
    t.to = (i * 10) % V;
    t.cost = 0;
    G[i].pb(t);
  }
  bfs01(1);
  cout << d[0] + 1 << endl;
  return 0;
}
