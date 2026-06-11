#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int,int>;
using PP = pair<int,pair<int,int>>;
using T = tuple<string,int,int>;
const ll INF = 1LL<<60;

vector<vector<P>> g;
vector<int> ans;

void dfs(int pre, int now, int col){
  ans[now] = col;
  for(P p: g[now]){
    if(p.first == pre) continue;
    if(p.second % 2) dfs(now, p.first, 1-col);
    else dfs(now, p.first, col);
  }
}

int main(){
  int n; cin >> n;
  g.resize(n);
  ans.resize(n, -1);
  for(int i = 0; i < n-1; i++){
    int a,b,c; cin >> a >> b >> c;
    a--; b--;
    g[a].push_back(P(b,c));
    g[b].push_back(P(a,c));
  }
  dfs(-1, 0, 0);
  for(int i = 0; i < n; i++) cout << ans[i] << endl;
  return 0;
}
