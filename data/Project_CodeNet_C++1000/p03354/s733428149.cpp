#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;

ll N, M;
vector<ll> p, x, y;

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

int main() {
    cin >> N >> M;
    p.resize(N);
    rep(i, N) {
        cin >> p[i];
        p[i]--;
    }

    x.resize(M);
    y.resize(M);

    UnionFind uf(N);
    rep(i, M) {
        ll tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        tmp1--;
        tmp2--;
        x[i] = tmp1;
        y[i] = tmp2;
        uf.connect(tmp1, tmp2);
    }

    ll ans = 0;
    rep(i, N) {
        if (uf.root(i) == uf.root(p[i])) {
            ans++;
        }
    }
    cout << ans << endl;
}