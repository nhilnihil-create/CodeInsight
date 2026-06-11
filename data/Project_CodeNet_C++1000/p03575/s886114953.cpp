#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<bool>> G(n, vector<bool>(n, false));
  int a[m], b[m], ans=0;
  for(int i=0; i<m; i++){
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
    G[a[i]][b[i]] = true;
    G[b[i]][a[i]] = true;
  }
  
  bool visit[n];
  for(int i=0; i<m; i++){
    G[a[i]][b[i]] = false;
    G[b[i]][a[i]] = false;
    
    for(int j=0; j<n; j++){
      visit[j] = false;
    }
    
    queue<int> que;
    int now;
    que.push(0);
    while(!que.empty()){
      now = que.front();
      que.pop();
      visit[now] = true;
      for(int j=0; j<n; j++){
        if(G[now][j]&&!visit[j]){
          que.push(j);
        }
      }
    }
    bool ok = true;
    for(int j=0; j<n; j++){
      ok &= visit[j];
    }
    if(!ok){
      ans++;
    }
    
    G[a[i]][b[i]] = true;
    G[b[i]][a[i]] = true;
  }
  cout << ans << endl;
  return 0;
}
