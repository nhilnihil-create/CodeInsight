#include <bits/stdc++.h>

using namespace std;

int N, M, cnt[200005][2], vis[200005];
char ch[200005];
vector<int> G[200005];
queue<int> que;

int main() {
  scanf("%d%d", &N, &M);
  scanf("%s", ch + 1);
  for (int i = 1, u, v; i <= M; i++) {
    scanf("%d%d", &u, &v);
    G[u].push_back(v), cnt[u][ch[v] - 'A']++;
    G[v].push_back(u), cnt[v][ch[u] - 'A']++;
  }
  for (int i = 1; i <= N; i++)
    if (!cnt[i][0] || !cnt[i][1]) vis[i] = true, que.push(i);
  while (!que.empty()) {
    int now = que.front();
    que.pop();
    for (auto to : G[now]) {
      if (vis[to]) continue;
      cnt[to][ch[now] - 'A']--;
      if (!cnt[to][0] || !cnt[to][1]) vis[to] = true, que.push(to);
    }
  }
  bool flag = false;
  for (int i = 1; i <= N && !flag; i++)
    if (!vis[i]) flag = true;
  puts(flag ? "Yes" : "No");
  return 0;
}
