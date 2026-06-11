

#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

struct UnionFind {
  vector<int> d;
  UnionFind(int n): d(n,-1) {}//-1で初期化
  int root(int x) {
    if (d[x] < 0) return x;//rootを負にする（構成node数x(-1))
    //root以外は親の番号
    return d[x] = root(d[x]);
    //return(root(d[x]))とするとメモできないが上の書き方だとメモができる
  }
  bool unite(int x, int y) {
    x = root(x); y = root(y);
    if (x == y) return false;
    if (d[x] > d[y]) swap(x,y);
    //swapすることで小さい方を大きい方につけられ計算量減らせる
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  bool same(int x, int y) { return root(x) == root(y);}
  //同じグループ化
  int size(int x) { return -d[root(x)];}
  //グループのnode数
    int group_num(int n){
        set<int> s;
        for(int i = 0; i < n; ++i){
            s.insert(root(i));
        }
        return int(s.size());}
};

int deg[100005];
vector<int> to[100005];

int main() {
  int n, m;
  cin >> n >> m;
  UnionFind uf(n);
  rep(i,m) {
    int a, b, z;
    cin >> a >> b>>z;
    --a; --b;
    deg[a]++;
    deg[b]++;
    //degの中に友達の数をメモ
    uf.unite(a,b);

  }

  int ans=uf.group_num(n);
  cout<<ans;
  return 0;
}
