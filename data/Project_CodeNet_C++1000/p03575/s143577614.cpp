#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;

int n, m, a[50], b[50];
bool visited[50], renketsu[50][50];

void dfs(int k) {
  visited[k] = true;
  rep(i,n) {
    if (visited[i]) continue;   //すでに訪問済なら飛ばす
    if (!renketsu[k][i]) continue;   //連結してないなら飛ばす
    dfs(i);  //残ったものについてdfs
  }
  return;
}

int main() {
  cin >> n >> m;
  rep(i,m) {
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
    renketsu[a[i]][b[i]] = renketsu[b[i]][a[i]] = true;
  }
  
  int ans = 0;
  
  rep(i,m) {
    renketsu[a[i]][b[i]] = renketsu[b[i]][a[i]] = false;
    rep(j,n) visited[j] = false;
    dfs(0);
    
    bool bridge = false;
    rep(l,n)
      if (!visited[l]) bridge = true;
    if (bridge) ans++;
    
    renketsu[a[i]][b[i]] = renketsu[b[i]][a[i]] = true;
  }
  
  cout << ans << endl;
}