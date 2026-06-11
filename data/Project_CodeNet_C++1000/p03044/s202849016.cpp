
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

struct UnionFind {
  vector<int> d; // 親の番号、但し根の場合はサイズのマイナス
  UnionFind(int n): d(n,-1) {}
  int root(int x) { // 根を見つける
    if (d[x] < 0) return x;
    return d[x] = root(d[x]); // 経路圧縮
  }
  bool unite(int x, int y) { // 結合
    x = root(x); y = root(y);
    if (x == y) return false;
    if (d[x] > d[y]) swap(x,y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  bool same(int x, int y) { return root(x) == root(y);} // 親が一緒
  int size(int x) { return -d[root(x)];} // サイズ
};

int main(){
    int n; // 頂点数
    cin>>n;
    UnionFind uf(2*n+1); // 初期化
    int u,v,w;
    rep(i,n-1){
        cin>>u>>v>>w;
        if(w%2==0){
            uf.unite(u,v);
            uf.unite(n+u,n+v);
        }
        else{
            uf.unite(u,n+v);
            uf.unite(n+u,v);
        }
    }
    cout<<"0"<<endl;
    for(int i=2;i<=n;i++){
        if(uf.same(1,i)) cout<<"0"<<endl;
        else cout<<"1"<<endl;
    }
    return 0;
}

