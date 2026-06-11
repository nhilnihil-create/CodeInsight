#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#define rep(i, f, n) for (int i = (f); i < (int)(n); i++)
#define repe(i, f, n) for (int i = (f); i <= (int)(n); i++)
using namespace std;
using ll = long long;
using pint = pair<int, int>;

const int MAX = 50;

int n, m;
int a[MAX], b[MAX];
bool g[MAX][MAX];
bool visited[MAX];

void dfs(int v) {
  visited[v] = true;
  // 連結判定
  rep(v2, 0, n) {
    if (!g[v][v2]) continue;
    if (visited[v2]) continue;
    dfs(v2);
  }
}

int main() {
  cin >> n >> m;
  rep(i, 0, m) {
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
    g[a[i]][b[i]] = g[b[i]][a[i]] = true;
  }

  int ans = 0;

  // 一旦橋を辺の連結を解除し、全てを未訪問にした状態で dfs で探索を行う.
  // 辺の連結を解除したことで visited に1つでも未訪問（到達できない）があれば橋
  rep(i, 0, m) {
    g[a[i]][b[i]] = g[b[i]][a[i]] = false;

    rep(j, 0, n) visited[j] = false;

    dfs(0);

    bool bridge = false;
    rep(j, 0, n) if (!visited[j]) bridge = true;
    if (bridge) ans++;

    g[a[i]][b[i]] = g[b[i]][a[i]] = true;
  }

  cout << ans << endl;

  return 0;
}
