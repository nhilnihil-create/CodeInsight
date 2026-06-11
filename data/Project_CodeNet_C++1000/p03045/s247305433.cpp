#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
  int n, m, ans = 0; cin >> n >> m;
  vector<vector<int>> v(n);
  rep(i, m){
    int x, y, z; cin >> x >> y >> z;
    x--; y--;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  queue<int> q;
  vector<bool> visited(n, false);
  rep(i, n){
    if(visited[i] == true) continue;
    ans++;
    q.push(i);
    visited[i] = true;
    while(q.size() > 0){
      int now = q.front(); q.pop();
      rep(j, v[now].size()){
        int next = v[now][j];
        if(visited[next] == true) continue;
        visited[next] = true;
        q.push(next);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
