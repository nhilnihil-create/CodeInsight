#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(v) v.begin(), v.end()
#define PRINT(v) for (auto x : (V)) cout <<x <<" " <<endl;
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
const ll MOD = 1000000007;
const ll INF = 10000000000000000;
vector<int> x4 = {0, 1, 0, -1}, x8 = {0, 1, 1, 1, 0, -1, -1, -1};
vector<int> y4 = {1, 0, -1, 0}, y8 = {1, 1, 0, -1, -1, -1, 0, 1};
template<class T> struct edge { int from, to; T cost;};
template<class T> inline bool chmin(T& a, T b){if (a>b){a = b; return true;}return false;}
template<class T> inline bool chmax(T& a, T b){if (a<b){a = b; return true;}return false;}
template<class T> inline T powerM(T a,T b){if (b==0) return 1;
T tmp = powerM(a,b/2); if (b%2==0) return tmp*tmp%MOD; else return tmp*tmp%MOD*a%MOD; }
template<class T> inline T power(T a,T b,T m){ if (b==0) return 1;
  T tmp = power(a,b/2,m); if (b%2==0) return tmp*tmp%m; else return tmp*tmp%m*a%m; }
template<class T> inline T gcd(T a, T b){if (b==0) return a; return gcd(b, a%b);}
template<class T> inline T lcm(T a, T b){return a / gcd(a,b) * b;}
// ax+by=gcd(a,b)を解く
template<class T> inline T extgcd(T a,T b,T &x,T &y){if (b==0){x=1; y=0; return a;} T d=extgcd(b,a%b,y,x); y -= a/b*x; return d;}
void hey(){ cout <<"hey" <<endl; }


// Union-Find木-----------------------------------------------
/* ここらへんと蟻本を参考に
<https://qiita.com/drken/items/cce6fc5c579051e64fab>
<http://baitop.hatenadiary.jp/entry/2018/06/26/224712>
sizeが必要なら2個目のリンクからいい感じに
*/
// UnionFind uf(N); // N:要素数

struct UnionFind{
  vector<int> par;  // 親ノードを格納
  vector<int> rank; // 木の深さを格納
  vector<int> sizes; // 木の大きさを格納

  UnionFind(int N = 1) : par(N), rank(N, 0), sizes(N) { // N要素で初期化する
    for (int i=0; i<N; i++) par[i] = i;
    for (int i=0; i<N; i++) sizes[i] = 1;
  }

  int root(int x){ // 木の根を求める。自分じゃなかったら親の根を調べていき調べたノードの親はすべて根に
    return par[x] == x ? x : par[x] = root(par[x]); // 経路圧縮も行う
  }

  bool same(int x, int y){ // x,yの木が同じかどうか
    return root(x) == root(y);
  }

  bool unite(int x, int y){ // xとyの木を併合
    x = root(x); y = root(y); // ここでx,yのroot同士の扱いにする
    if (x == y) return false; // 元々同じならそのまま
    if (rank[x] < rank[y]) swap(x, y); // rank[x] >= rank[y]になるようにswap
    if (rank[x] == rank[y]) rank[x]++; // 元のrankが同じなら親になる方のrankは1増える
    par[y] = x;
    sizes[x] += sizes[y];
    return true;
  }

  int size(int x){
    return sizes[par[x]];
  }
};


int main() {
  int N,M; cin >>N >>M;
  UnionFind uf(N);
  vector<int> A(M),B(M);
  rep(i, M){
    cin >>A[i] >>B[i]; A[i]--; B[i]--;
  }
  /*橋が崩落したとして、崩落した後もaとbが連結ならばまあいいでしょう
  AとBが連結でなくなれば、崩落した後のsize(A) * size(B) の分だけ不便さが増える
  UnionFindでやりたいので、逆から見ていってAとBが繋がると考える
  この時減少する不便さはAとBが元々連結なら0、そうでなければsize(A) * size(B)の分だけ減少する
  答えるときはこれらを逆に見ていって足していけばよい
  */
  vector<ll> inc(M);
  for (int i=M-1; i>=0; i--){
    int a = A[i], b = B[i];
    if (uf.same(a, b)) continue; // 元々連結なら繋がってもうれしくない
    inc[i] = (ll)uf.size(a) * (ll)uf.size(b);
    uf.unite(a, b);
  }
  ll res = 0;
  rep(i, M){
    res += inc[i];
    cout <<res <<endl;
  }

}
