#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

struct Edge {
  int to, w;
  Edge(int t, int w) :to(t), w(w) {}
};

struct Tree {
  int N;
  vector<vector<Edge>> edges;

  void addEdge(int a, int b) { addEdge(a, b, 1); }
  void addEdge(int a, int b, int w) { edges[a].emplace_back(b, w); }

  Tree(int N) :N(N), edges(N) {}

  long long diam(){
    setDist(0);
    int start;
    long long maxd = -1;
    rep(i, N) {
      if (dist[i] > maxd) {
        maxd = dist[i];
        start = i;
      }
    }
    setDist(start);
    rep(i, N) maxd = max(maxd, dist[i]);
    return maxd;
  }

  vector<long long> dist;
  void setDist(int s) {
    dist = vector<long long>(N, -1);
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
      int x = q.front(); q.pop();
      for (Edge e : edges[x]) {
        if (dist[e.to] != -1) continue;
        dist[e.to] = dist[x] + e.w;
        q.push(e.to);
      }
    }
  }
};

int main(){
  int N; cin >> N;
  Tree G(N);
  rep(i, N - 1) {
    int x, y; cin >> x >> y;
    x--; y--;
    G.addEdge(x, y);
    G.addEdge(y, x);
  }

  long long diam = G.diam();

  if ((diam + 1) % 3 == 2) cout << "Second" << endl;
	else cout << "First" << endl;
}
