#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

int n, m, cnt[MAXN][2], del[MAXN];
vector<int> G[MAXN];
char ch[MAXN];
queue<int> Q;

void erase(int x) {
  int v = (ch[x] == 'A' ? 0 : 1);
  for(int i = 0; i < G[x].size(); i++) {
    int nx = G[x][i];
    --cnt[nx][v];
  }
  del[x] = 1;
  Q.push(x);
}

int main() {
  scanf("%d %d", &n, &m);
  scanf("%s", ch + 1);
  for(int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    G[x].push_back(y);
    G[y].push_back(x);
  }
  for(int i = 1; i <= n; i++) {
    for(int j: G[i]) {
      if(ch[j] == 'A') ++cnt[i][0];
      if(ch[j] == 'B') ++cnt[i][1];
    }
  }
  for(int i = 1; i <= n; i++) {
    if(!cnt[i][0] || !cnt[i][1]) {
      erase(i);
    }
  }
  while(!Q.empty()) {
    int cur = Q.front(); Q.pop();
    for(int i = 0; i < G[cur].size(); i++) {
      int nx = G[cur][i];
      if(!del[nx]) {
        if(!cnt[nx][0] || !cnt[nx][1]) {
          erase(nx);
        }
      }
    }
  }
  bool ok = false;
  for(int i = 1; i <= n; i++) {
    if(!del[i]) {
      ok = true;
    }
  }
  puts(ok ? "Yes" : "No");
  return 0;
}
