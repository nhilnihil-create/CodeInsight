// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(ll __x = __start; __x < __end; __x++)

typedef pair<int, int> Edge;

int main() {
  int n, m; cin >> n >> m;
  vector<Edge> G[50];
  loop(i,0,m) {
    int a, b; cin >> a >> b; a--;b--;
    G[a].emplace_back(b, i);
    G[b].emplace_back(a, i);
  }
  
  int ans = 0;
  loop(i,0,m) {
    vector<bool> done(n, false);
    queue<int> Q;
    Q.push(0);
    done[0] = true;
    int cnt = 1;
    while (Q.size()) {
      int v = Q.front(); Q.pop();
      for (auto &&edge: G[v]) {
        if (edge.second == i) continue;
        if (done[edge.first]) continue;
        done[edge.first] = true;
        cnt++;
        Q.push(edge.first);
      }
    }
    
    ans += cnt < n;
  }
  cout << ans << endl;
  return 0;
}
