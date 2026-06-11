#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
vector<pair<int,int>> mp[100010];
ll dist[100010];
bool used[100010] = {};
int n, m;
bool ok = true;

void dfs(int a) {
  if (used[a]) return;
  used[a] = true;
  if (dist[a] == INF) {
    dist[a] = 0;
  }
  for (int i = 0; i < mp[a].size(); i++) {
    int next = mp[a][i].first;
    int d = mp[a][i].second;
    if (!used[next]) {
      dist[next] = dist[a] + d;
      dfs(next);
    } else {
      if (dist[next] != dist[a] + d) {
        ok = false;
        return;
      }
    }
    if (!ok) return;
  }
}

int main(){
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int l, r, d;
    cin >> l >> r >> d;
    mp[l].push_back(make_pair(r, d));
    mp[r].push_back(make_pair(l, -d));
  }
  for (int i = 1; i <= n; i++) {
    dist[i] = INF;
  }
  for (int i = 1; i <= n; i++) {
    dfs(i);
    if (!ok) break;
  }
  if (ok) puts("Yes");
  else puts("No");
  return 0;
}
