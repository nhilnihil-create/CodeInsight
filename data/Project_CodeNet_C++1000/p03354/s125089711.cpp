#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
#define INF 1000000000000
#define MOD 1000000007
using ll = long long;

struct UnionFind{
  /*データメンバ*/
  vector<int> par; //par[i]:iの親の番号。
  /*コンストラクタ。独自の初期化処理などを行いたいときにコンストラクタを使う。引数の数を変えることで複数のコンストラクタを定義可能。*/
  UnionFind(int N) : par(N) {/*:の後ろに記述されたデータメンバの初期化を行う。*/
    rep(i,N)par[i]=i;
  }

  int root(int x){
    if(par[x]==x) return x;
    return par[x] = root(par[x]);
  }

  void unite(int x, int y){//unite trees
    int rx = root(x);
    int ry = root(y);
    if(rx == ry) return;
    par[rx] = ry;
  }

  bool same(int x, int y){
    int rx = root(x);
    int ry = root(y);
    return rx == ry;
  }
};

int main(){
  int N,M; cin>>N>>M;
  vector<int> P(N); rep(i,N)cin>>P.at(i);
  UnionFind tree(N+1);
  rep(i,M){
    int x,y; cin>>x>>y;
    tree.unite(x,y);
  }
  ll res = 0;
  rep(i,N){
    if(P.at(i)==i+1)res++;
    else if(tree.same(P.at(i),i+1))res++;
  }
  cout<<res<<endl;
}
