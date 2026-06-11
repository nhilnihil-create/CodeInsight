#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
#define equals(a, b) (fabs((a) - (b)) < EPS)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const ll mod2 = 998244353;
const int INF = 1e9;
const long double EPS = 1e-10;
const int MAX = 1e5;

struct Edge {
  int f, t, c;

  Edge(int f, int t, int c): f(f), t(t), c(c) {}
};

vector<Edge> G[MAX];
vector<int> d(MAX, INF);
bool visited[MAX];

void dijkstra(int u) {
  d[u] = 1;
  list<Edge> q;
  q.push_back(Edge(u, u, 0));
  while (!q.empty()) {
    Edge e = q.front();
    q.pop_front();
    if (visited[e.t]) continue;
    visited[e.t] = true;
    d[e.t] = d[e.f] + e.c;
    for (Edge f: G[e.t]) {
      if (f.c == 0) q.push_front(f);
      else if (f.c == 1) q.push_back(f);
    }
  }
}

int main() {
  int k;
  cin >> k;

  rep(i, k) G[i].push_back(Edge(i, (i + 1) % k, 1));
  rep(i, k) G[i].push_back(Edge(i, (i * 10) % k, 0));
  dijkstra(1);
  cout << d[0] << endl;




  
  return 0;
}