#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
  int n; cin >> n;
  vector<vector<pair<int, int>>> a(n);
  rep(i,n - 1){
    int u, v, w; cin >> u >> v >> w;
    u--;
    v--;
    a[u].push_back(make_pair(v, w));
    a[v].push_back(make_pair(u, w));
  }
  queue<int> q;
  vector<bool> visited(n, false);
  vector<int> dis(n);
  q.push(0);
  visited[0] = true;
  dis[0] = 0;
  while(q.size() > 0){
    int now = q.front(); q.pop();
    rep(i, a[now].size()){
      int next = a[now][i].first, disnext = a[now][i].second;
      if(visited[next] == true) continue;
      visited[next] = true;
      dis[next] = dis[now] + disnext;
      q.push(next);
    }
  }
  rep(i, n){
    if(dis[i] % 2 == 0) cout << 0 << endl;
    else cout << 1 << endl;
    //cout << dis[i] << endl;
  }
  return 0;
}
