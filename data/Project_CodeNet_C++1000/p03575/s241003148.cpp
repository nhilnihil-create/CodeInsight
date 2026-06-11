#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

vector<int> seen;
vector<vector<int>> g;
void dfs(int x){
  if(seen[x]) return ;
  seen[x] = 1;
  for (int nx : g[x]){
    dfs(nx);
  }
}

int main(){
  int n, m;
  cin >> n >> m;
  vector<int> a(m), b(m);
  rep(i, m){
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
  }
  
  int ans = 0;
  rep(i, m){
    g.assign(n, vector<int>());
    rep(j, m){
      if (i == j) continue ;
      g[a[j]].pb(b[j]);
      g[b[j]].pb(a[j]);
    }
    seen.assign(n, 0);
    dfs(0);
    rep(j, n){
      if(seen[j] == 0){
        ans++;
        break ;
      }
    }
  }
  cout << ans << endl;
}