#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int limit = 50;
int n, m;
int a[limit], b[limit];

bool graph[limit][limit];
bool visited[limit];

void dfs(int v) {
  visited[v] = true;
  for (int v2 = 0; v2 < n; ++v2) {
    if (graph[v][v2] == false) continue;
    if (visited[v2] == true) continue;
    dfs(v2);
  }
}


int main(void) {
  cin >> n >> m;

  rep(i, m) {
    cin >> a[i] >> b[i];
    --a[i];
    --b[i];
    graph[a[i]][b[i]] = graph[b[i]][a[i]] = true;
  }

  int ans = 0;

  rep(i, m) {
    graph[a[i]][b[i]] = graph[b[i]][a[i]] = false;
    rep(j, n) {
      visited[j] = false;
    }

    dfs(0);

    bool bridge = false;
    rep(j, n) if (visited[j] == false) bridge = true;
    if (bridge) ++ans;

    graph[a[i]][b[i]] = graph[b[i]][a[i]] = true;
  }

  cout << ans << endl;
  
  return 0;
}