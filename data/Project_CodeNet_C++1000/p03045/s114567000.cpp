#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
const int MOD = 1000000007;
const int INF = 1e18;
using Graph = vector<vector<int>>;

//UnionFind
struct UnionFind{
  vector<int> Par;

  //N個の独立した根として初期化
  UnionFind(int N) : Par(N) {
    for(int i = 0; i < N; i++) Par[i] = i;
  }

  //どこの根に属するか得る再帰関数
  int root(int X){
    if( Par.at(X) == X ) return X;
    else return Par.at(X) = root(Par.at(X));
  }

  //XとYが同じ根に属するか判定
  bool same(int X, int Y){
    return root(X) == root(Y);
  }

  //XとYの木を合体
  void unite(int X, int Y){
    X = root(X);
    Y = root(Y);
    if( X == Y ) return;
    Par.at(X) = Y;
  }
};


signed main() {
  int N, M;
  cin >> N >> M;

  UnionFind UF(N);
  Graph G(N);
  for( int i = 0; i < M; i++ ){
    int X, Y, Z;
    cin >> X >> Y >> Z;
    X--;
    Y--;
    UF.unite(X, Y);
  }

  set<int> num;
  for( int i = 0; i < N; i++ ){
    int R = UF.root(i);
    if( num.count(R) ) continue;
    num.insert(R);
  }
  cout << num.size() << endl;

 }
