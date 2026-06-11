#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

vector<vector<P>> G;
vector<int> res;

void dfs(int v,int p,int c){//v 今の頂点　p vの親　c vに塗るカラー
  res[v]=c;//vに塗った
  for(auto e : G[v]){//そのvに対してつながっている頂点を全部見る
    if(e.first==p)continue;//それが親だった場合はじく
    if(e.second&1)dfs(e.first,v,1-c);//ビットで奇数だった場合判定 見た頂点をbfs再帰する 親は今の頂点
    else dfs(e.first,v,c);
  }
}

int main() {
  int n;
  cin >>n;
  G.assign(n, vector<P>());
  rep(i,n-1){
    int u,v,w;
    cin>>u>>v>>w;
    --u;--v;//配列に合わせる処理
    G[u].push_back(P(v,w));//uとつながるvを配列
    G[v].push_back(P(u,w));
  }
  res.assign(n,0);
  dfs(0,-1,1);
  for(auto v:res) cout <<v<<endl;
}