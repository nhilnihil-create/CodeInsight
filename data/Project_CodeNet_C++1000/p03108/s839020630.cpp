#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef long long ll;
typedef pair<int,int> P;

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
		return -Parent[root(A)];//親をとってきたい
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
//UnionFind Uni(N);
//Uni.connect;

int main(){
    int n,m;
    cin >> n >> m;
    int a[m],b[m];
    rep(i,m){
        cin >> a[i] >> b[i];
        a[i]--,b[i]--;
    }
    UnionFind Uni(n);
    ll sum = (ll)n*(n-1)/2;
    ll ans[m];
    rep(i,m){
        ans[m-1-i]=sum;
        ll sizea = Uni.size(a[m-1-i]);
        ll sizeb = Uni.size(b[m-1-i]);
        if(Uni.root(a[m-1-i])!=Uni.root(b[m-1-i]))sum -= sizea*sizeb;
        Uni.connect(a[m-1-i],b[m-1-i]);
    }
    rep(i,m){
        cout << ans[i] << endl;
    }
}