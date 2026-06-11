#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;

bool graph[55][55];
bool seen[55];

void dfs(int i,int n){
  seen[i] = true;
  for(int j = 0;j < n;j++){
    if(graph[i][j] == false) continue;
    if(seen[j] == true) continue;
    dfs(j,n);
  }
  return;
}

int main(){
  int n,m; cin >> n >> m;
  vector<int> a(m),b(m);
  rep(i,m){
    cin >> a[i] >> b[i];
    --a[i];--b[i];
    graph[a[i]][b[i]] = graph[b[i]][a[i]] = true;
  }

  int ans = 0;
  rep(i,m){
    graph[a[i]][b[i]] = graph[b[i]][a[i]] = false;
    rep(j,n) seen[j] = false;
    dfs(0,n);
    rep(j,n) {
      if(!seen[j]) {
        //printf("%d %d\n",a[i],b[i]);
        ans++;
        break;
      }
    }
    graph[a[i]][b[i]] = graph[b[i]][a[i]] = true;
  }
  cout << ans << endl;
}