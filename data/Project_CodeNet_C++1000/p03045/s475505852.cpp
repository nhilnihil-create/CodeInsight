#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

class UnionFind {
public:
  //親の番号を格納する。親だった場合は-(その集合のサイズ)
  vector<int> Parent;

  //作るときはParentの値を全て-1にする
  //こうすると全てバラバラになる
  UnionFind(int N) {
    Parent = vector<int>(N, -1);
  }

  //Aがどのグループに属しているか調べる
  int root(int A) {
    if (Parent[A] < 0) return A;
    return Parent[A] = root(Parent[A]);
  }

  //自分のいるグループの頂点数を調べる
  int size(int A) {
    return -Parent[root(A)];//親をとってきたい]
  }

  //AとBをくっ付ける
  bool connect(int A, int B) {
    //AとBを直接つなぐのではなく、root(A)にroot(B)をくっつける
    A = root(A);
    B = root(B);
    if (A == B) {
      //すでにくっついてるからくっ付けない
      return false;
    }

    //大きい方(A)に小さいほう(B)をくっ付けたい
    //大小が逆だったらひっくり返しちゃう。
    if (size(A) < size(B)) swap(A, B);

    //Aのサイズを更新する
    Parent[A] += Parent[B];
    //Bの親をAに変更する
    Parent[B] = A;

    return true;
  }
};

ll N, M;

int main() {
    cin >> N >> M;
    UnionFind uf = UnionFind(N);

    rep(i, M) {
        ll x, y, z;
        cin >> x >> y >> z;
        x--; y--;
        uf.connect(x, y);
    }

    set<ll> st;
    rep(i, N) {
        ll par = uf.root(i);
        st.insert(par);
    }
    cout << st.size() << endl;
}