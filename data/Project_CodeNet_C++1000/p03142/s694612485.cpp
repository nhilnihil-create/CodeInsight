#include <bits/stdc++.h>
#define rep(i,N) for(int i=0;i<N;i++)
using namespace std;
long long  INF=1000000000000000000;
long long mod=1000000007;
using namespace std;


int main(){
int n,m;
cin>>n>>m;

vector<vector<int>>to(n);
vector<int>in(n);//n頂点に対して入ってくる有効グラフの数

rep(i, n-1+m) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    to[a].push_back(b);
    in[b]++;
  }
  queue<int> que;
  rep(i, n) {
    if (!in[i])
    //根の決定
      que.push(i);
  }

  vector<int> tps;
  //queueを用いたトポロジカルソート
  //幅優先探索
  while (!que.empty()) {
    int a = que.front();
    que.pop();
    tps.push_back(a);
    for (auto e : to[a])
    //現在調べている頂点の行き先について
     {
      in[e]--;
      if (!in[e])
      //入ってくる辺が一つの頂点を次の探索対象にする
        que.push(e);
    }
  }
  vector<int> ans(n);//初期値0が入る
  rep(i, n) {
    for (auto e : to[tps[i]])
    //最後に更新された親が本当の親
      ans[e] = tps[i]+1;
  }
  rep(i, n)
    cout << ans[i] << endl;

 return 0;
}
/*

*/