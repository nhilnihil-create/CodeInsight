#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for (ll i=0; i<n; ++i)
#define all(c) begin(c),end(c)
/*
ワーシャルして、3の候補
それの組み合わせ、nC2かな
ああ、追加した道も通っていいのか…
毎回やり直しは無理
逆に候補減らしていくとか？
数学的なやつか
二部グラフなら違う色同士結べる。＝B*W-M
そうじゃないなら完全グラフ。=nC2-M
*/
vector<vector<ll>> G;
int colors[200005];
bool is_bipartite_graph(int v, int c) {
    colors[v] = c;
    for (int u: G[v]) {
        if (colors[u] == c) {
            return false;
        }
        if (colors[u] == 0 && !is_bipartite_graph(u, -c)) {
            return false;
        }
    }
    return true;
}

int main(){
  ll N,M; cin>>N>>M;
  G.assign(N+1, vector<ll>(0,0));
  rep(i,M){
    ll a,b; cin>>a>>b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  ll ans=0;
  if(is_bipartite_graph(1, 1)==true){
    ll w=0, b=0;
    for(ll i=1; i<=N; i++){
      if(colors[i]>0) w++;
      else if(colors[i]<0) b++;
    }
    ans=w*b-M;
  }
  else ans=(N*(N-1))/2-M;
  cout<<ans<<endl;
}