#include <bits/stdc++.h>
#define ll long long;
using namespace std;

void dfs(int pos, vector< vector< int > > &v, vector< bool > &visit){
  if(visit[pos]) return;
  else{
    visit[pos] = true;
    for(auto x: v[pos]){
      dfs(x,v,visit);
    }
  }
}

int main(){
  int n, m; cin >> n >> m;
  int ans = 0;
  int a, b, c;
  vector< bool > v(n + 1,0);
  vector< vector< int > > look(n + 1);
  for(int i = 0; i < m; ++i){
    cin >> a >> b >> c;
    look[a].push_back(b);
    look[b].push_back(a);
  }
  for(int i = 1; i < (n + 1); ++i){
    if(!v[i]){
      ans++;
      dfs(i,look,v);
    }
  }
  cout << ans << '\n';
}
