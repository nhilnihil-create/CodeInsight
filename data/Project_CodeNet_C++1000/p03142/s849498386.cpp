#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

// 頂点数、変数
int v, e;
const int MAX_N = 100100;
// 隣接リスト
vector<int> to[MAX_N];
vector<int> from[MAX_N];
bool used[MAX_N];
// トポロジカルソートされた数列
vector<int> tps;

void dfs(int u) {
  if(used[u]) return;
  used[u] = true;
  for(int i: to[u]) dfs(i);
  // 帰りがけ順で追加
  tps.push_back(u);
}

void tsort() {
  for(int i=0; i<v; ++i) dfs(i);
  reverse(tps.begin(), tps.end());
}

int main(void){
  int n,m;
  cin >> n >> m;
  v = n;
  e = n+m-1;
  for(int i=0; i<e; ++i) {
    int s, t;
    cin >> s >> t;
    s--;t--;
    to[s].push_back(t);
    from[t].push_back(s);
  }

  tsort();
  int rvs[v];
  //rep(i,n)cout << tps[i] << endl;
  rep(i,v){
    int t = tps[i];
    rvs[t] = i;
  }
  //rep(i,n)cout << rvs[i] << endl;
  int ans[v];
  rep(i,v){
    if(i==tps[0]){
      cout << 0 << endl;
      continue;
    }
    int mx = 0;
    for(int j:from[i]){
      mx = max(rvs[j],mx);
      // cout << rvs[j] << endl;
    }
    cout << tps[mx]+1 << endl;
  }
  return 0;
}
