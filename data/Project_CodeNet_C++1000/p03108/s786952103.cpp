#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define maxs(a, b) a = max(a, b)
#define mins(a, b) a = min(a, b)
using namespace std;
typedef long long ll;
typedef pair<double, int> P;
const ll linf = (1ll << 61);
const int inf = 1001001001;
const int mod = 1000000007;

class UnionFind {
public:
	//親の番号を格納する。親だった場合は-(その集合のサイズ)
	vector<int> Parent;
	//作るときはParentの値を全て-1にする
	//こうするとすべてバラバラになる
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
	//AとBをくっつける
	bool connect(int A, int B) {
		//AとBを直接つなぐのではなく、root(A)にroot(B)をくっつける
		A = root(A);
		B = root(B);
		if (A == B) {
			//すでにくっついているからくっつけない
			return false;
		}
		//大きい方(A)に小さいほう(B)をくっつけたい
		//大小が逆だったらひっくり返しちゃう
		if (size(A) < size(B)) swap(A, B);
		//Aのサイズを更新する
		Parent[A] += Parent[B];
		//Bの親をAに変更する
		Parent[B] = A;

		return true;
	}
	//AとBが同じグループにいるか
	bool same(int A, int B) { return root(A) == root(B); }
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<ll> ans;
	UnionFind Uni(n);
	vector<int> a(m), b(m);
	rep(i, m) cin >> a[i] >> b[i], a[i]--, b[i]--;
	reverse(all(a));
	reverse(all(b));
	ll sum = 0;
	rep(i, m) {
		ans.push_back(sum);
		if (!Uni.same(a[i], b[i])) {
			ll res = Uni.size(a[i]);
			res *= Uni.size(b[i]);
			sum += res;
			Uni.connect(a[i], b[i]);
		}
	}
	reverse(all(ans));
	for (ll c : ans) cout << sum - c << endl;
 	return 0;
}
