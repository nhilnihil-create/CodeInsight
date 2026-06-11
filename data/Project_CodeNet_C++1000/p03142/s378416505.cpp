#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define F first
#define S second

using namespace std;
typedef pair<int,int> P;
typedef vector<int> ivec;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


const int MOD=1000000007;
int INF=100100100100100;

using Graph = vector<vector<int>>;
/* topo_sort(G): グラフG をトポロジカルソート
    返り値: トポロジカルソートされた頂点番号
    計算量: O(|E|+|V|)
 */
void dfs(Graph &G, int v, vector<bool> &used, vector<int> &ans) {
    used[v] = true;
    for (int e : G[v]) {
        if (!used[e]) {
            dfs(G, e, used, ans);
        }
    }
    ans.push_back(v);  // 帰りがけにpush_back
}
vector<int> topo_sort(Graph &G) {  // bfs
    vector<int> ans;
    int n = (int)G.size();
    vector<bool> used(n, false);
    for (int v = 0; v < n; v++) {  // 未探索の頂点ごとにDFS
        if (!used[v]) dfs(G, v, used, ans);
    }
    reverse(ans.begin(), ans.end());  // 逆向きなのでひっくり返す
    return ans;
}

signed main(){
  int n,m;cin>>n>>m;
  Graph g(n);
  Graph rg(n);
  ivec tj(n);
  ivec ans(n);
  rep(i,n+m-1){
    int a,b;cin>>a>>b;a--;b--;
    g[a].pb(b);
    rg[b].pb(a);
  }
  ivec topo=topo_sort(g);
  rep(i,n)tj[topo[i]]=i;
  for(int v:topo){
    if(v==topo[0]){
      ans[v]=0;
      continue;
    }
    int ma=-1;
    int res=-10;
    for(int w:rg[v]){
      //cout<<tj[w]<<endl;
      if(ma<tj[w])ma=tj[w],res=w;
    }
    ans[v]=res+1;
  }
  rep(i,n)cout<<ans[i]<<endl;
  return 0;
}
