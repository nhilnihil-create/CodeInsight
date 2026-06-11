#include <bits/stdc++.h>
#define int long long
using namespace std;

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
  vector<int> A(N);
  for( int i = 0; i < N; i++ ) cin >> A.at(i);

  UnionFind T(N);

  for( int i = 0; i < M; i++ ){
    int X, Y;
    cin >> X >> Y;
    X--;
    Y--;
    T.unite(X, Y);
  }

  int ans = 0;
  for( int i = 0; i < N; i++ ){
    if( T.same(i, A.at(i)-1) ) ans++;
  }
  cout << ans << endl;


}