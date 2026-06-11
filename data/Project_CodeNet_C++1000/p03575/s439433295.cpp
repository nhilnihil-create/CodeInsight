#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;


int n, m;
int a[60], b[60];
bool graph[60][60];
bool visited[60];

void dfs(int x) {
  visited[x] = true;
  rep(w,60) {
    if(!graph[x][w]||visited[w]) continue;
    dfs(w);
  }
}

int main() {
  cin >> n >> m;
  rep(i,m) {
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
    graph[a[i]][b[i]] = graph[b[i]][a[i]] = true;
  }
  int ans = 0;
  rep(i,m) {
    graph[a[i]][b[i]] = graph[b[i]][a[i]] = false;
    rep(j,60) visited[j] = false;
    dfs(0);
    rep(j,n) {
      if(visited[j]==false) {
        ans++;
        break;
      }
    }
    graph[a[i]][b[i]] = graph[b[i]][a[i]] = true;
  }
  cout << ans << endl;
  return 0;
}