#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
#define sp <<" "<<
#define cst(x) cout<<fixed<<setprecision(x)
#define pi 3.14159265359
#define mod 1000000007
struct edge {
    int to; 
    int weight;
    edge(int t, int w) : to(t),weight(w) {}
};
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vl = vector<ll>;
using Graphi = vector<vi>;
using Graphe = vector<vector<edge> >;
using que_a = priority_queue<int, vector<int>, greater<int> >;
using que_d = priority_queue<int>;
using pint = pair<int,int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

struct UnionFind
{
  // par[i]：データiが属する木の親の番号。i == par[i]のとき、データiは木の根ノードである
  vector<int> par;
  // sizes[i]：根ノードiの木に含まれるデータの数。iが根ノードでない場合は無意味な値となる
  vector<int> sizes;

  UnionFind(int n) : par(n), sizes(n, 1) {
    // 最初は全てのデータiがグループiに存在するものとして初期化
    rep(i,n) par[i] = i;
  }

  // データxが属する木の根を得る
  int root(int x) {
    if (x == par[x]) return x;
    return par[x] = root(par[x]);  // 根を張り替えながら再帰的に根ノードを探す
  }

  // 2つのデータx, yが属する木をマージする
  void unite(int x, int y) {
    // データの根ノードを得る
    x = root(x);
    y = root(y);

    // 既に同じ木に属しているならマージしない
    if (x == y) return;

    // xの木がyの木より大きくなるようにする
    if (sizes[x] < sizes[y]) swap(x, y);//mergeテク

    // xがyの親になるように連結する
    par[y] = x;
    sizes[x] += sizes[y];
    sizes[y] = 0;  // sizes[y]は無意味な値となるので0を入れておいてもよい
  }

  // 2つのデータx, yが属する木が同じならtrueを返す
  bool connected(int x, int y) {
    return root(x) == root(y);
  }

  // データxが含まれる木の大きさを返す
  ll size(int x) {
    return sizes[root(x)];
  }
};

int main(){

    ll n,m; cin >> n >> m;
    vector<pint> node(m);
    rep(i,m){
        int a,b; cin >> a >> b;
        --a;--b;
        node.at(i) = make_pair(a,b);
    } 
    reverse(all(node));
    vector<ll> ans(m);
    ans.at(0) = n*(n-1)/2;
    UnionFind tree(n);
    for(int i = 1; i < m; i++){

        ll x = node.at(i-1).first;
        ll y = node.at(i-1).second;
        if(tree.connected(x,y)) ans.at(i) = ans.at(i-1);
        else ans.at(i) = ans.at(i-1) - tree.size(x)*tree.size(y);
        tree.unite(node.at(i-1).first,node.at(i-1).second);

    }

    reverse(all(ans));
    rep(i,m) cout << ans.at(i) << endl;

    return 0;

}