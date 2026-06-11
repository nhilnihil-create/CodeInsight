#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
const ll MOD = 1000000007;
const ll INF = 9999999999;
const int INFI=2147483647;
template<class T> inline bool chmin(T& a, T b){if (a>b){a = b; return true;}return false;}
template<class T> inline bool chmax(T& a, T b){if (a<b){a = b; return true;}return false;}
template<class T> inline T powerM(T a,T b){if (b==0) return 1;
  T tmp = powerM(a,b/2); if (b%2==0) return tmp*tmp%MOD; else return tmp*tmp%MOD*a%MOD; }


template<class Abel> struct UnionFind {
  vector<int> par;
  vector<int> rank;
  vector<Abel> diff_weight; // 親ノードとの距離みたいなもの。重み。根では0

  UnionFind(int N = 1, Abel SUM_UNITY = 0) : par(N), rank(N, 0), diff_weight(N, SUM_UNITY){
    for (int i=0; i<N; i++) par[i] = i;
  }

  int root(int x){
    if (par[x] == x) return x;
    else{
      int r = root(par[x]); // この時点で経路圧縮を行っておく
      diff_weight[x] += diff_weight[par[x]]; // 根の方から順々に重みが決定していく
      return par[x] = r;
    }
  }

  Abel weight(int x){ // ノードxの重みを返す
    root(x); // 経路圧縮
    return diff_weight[x];
  }

  bool same(int x, int y){
    return root(x) == root(y);
  }

  bool unite(int x, int y, Abel w){ // 重み差分がweight(y)-weight(x) = wとなるように併合
    w += weight(x); w -= weight(y); // 実際に繋げるのはx,yのroot同士なので重み差分を修正
    x = root(x); y = root(y);
    if (x == y) return false;
    if (rank[x] < rank[y]) swap(x, y), w = -w; // swapに併せてwも符号反転
    if (rank[x] == rank[y]) rank[x]++;
    par[y] = x;
    diff_weight[y] = w; // xrootがyrootの親になる
    return true;
  }

  Abel diff(int x, int y){ // 重みの差分を返す
    return weight(y) - weight(x);
  }
};

int main() {
  int N,M; cin >>N >>M;
  UnionFind<int> uf(N);
  bool ok = true;
  rep(q, M){
    int l,r,d; cin >>l >>r >>d;
    l--; r--;
    if (!uf.unite(l, r, d)){
      if (d != uf.diff(l, r)){
        ok = false; break;
      }
    }
  }
  cout <<(ok ? "Yes" : "No") <<endl;
}