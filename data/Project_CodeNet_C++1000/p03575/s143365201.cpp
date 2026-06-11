#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define fr(i,n) for(int i=0;i<(n);++i)
#define Fr(i,n) for(int i=1;i<=(n);++i)
#define ifr(i,n) for(int i=(n)-1;i>=0;--i)
#define iFr(i,n) for(int i=(n);i>0;--i)

bool graph[50][50];
bool visited[8];

int dfs(int a, int n, bool visited[]){
  bool all_visited = true;
  fr(i,n) if(visited[i] == false) all_visited = false;
  
  if(all_visited) return 1;
  int ret = 0;
  fr(i, n) {
    if(visited[i]) continue;
    if(graph[a][i] == true){
      visited[i] = true;
      ret += dfs(i, n, visited);
//      visited[i] = false;
    }
  }  
 // if(graph[1][2] == false) cout << ret << endl;
  return ret;
}

int main(void) {
  int n,m;cin>>n>>m;
  fr(i, m) {
    int a,b;cin>>a>>b;
    a--;b--;
    graph[a][b] = graph[b][a] = true;
  }
  int ans = 0;
  fr(i,n) fr(j,n){
    if(i>j) continue;
    bool visited[50];

    if(graph[i][j] == true) {
      graph[i][j] = graph[j][i] = false;
 //     cout << dfs(0, n, visited) << "aaaa" << endl;
      int t = 0;
      fr(l, n) {
        fr(k, n) visited[k] = false;
        visited[l] = true;
        t += dfs(l, n, visited);
      }
      if (t == 0) ans++;
 //     cout << i << " " << j << endl;
    //  cout << ans << endl;
      graph[i][j] = graph[j][i] = true;
    }
  }
  cout << ans << endl;
  return 0;
}