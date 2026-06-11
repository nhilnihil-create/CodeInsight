// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(ll __x = __start; __x < __end; __x++)

typedef pair<int, int> Edge;

int main() {
  int h, w; cin >> h >> w;
  vector<Edge> G[10];
  loop(i,0,10) loop(j,0,10) {
    int w; cin >> w;
    if (w > 0) G[j].emplace_back(i, w);
  }
  const int INF = 1000000000;
  vector<int> D(10, INF);
  {
    vector<bool> done(10, false);
    priority_queue<pair<int, int> > Q;
    Q.push({ 0, 1 });
    D[1] = 0;
    while (Q.size()) {
      auto p = Q.top(); Q.pop();
      int v = p.second;
      if (done[v]) continue;
      done[v] = true;
      for (auto &&edge: G[v]) {
        int u = edge.first, w = edge.second;
        if (D[u] > D[v] + w) {
          D[u] = D[v] + w;
          Q.push({ -D[u], u });
        }
      }
    }
  }
  
  ll ans = 0;
  loop(y,0,h) loop(x,0,w) {
    int a; cin >> a;
    if (a == -1) continue;
    ans += D[a];
  }
  cout << ans << endl;
  return 0;
}
