#include <cmath>
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<set>
#include<map>
#include<bitset>
#include<iomanip>
#include<stack>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
ll n, m;
class union_find {
public:
	vector<int>par;
	vector<int>size;

	union_find(int n) : par(n), size(n, 1) {
		for (int i = 0; i < n; i++) {
			par[i] = i;//最初の親は自分自身
		}
	}
	void init(int n) {
		par.resize(n);
		size.assign(n, 1);
		for (int i = 0; i < n; i++) {
			par[i] = i;//最初の親は自分自身
		}
	}
	//木の根を求める
	int root(int x) {
		if (par[x] == x) {
			return x;
		}
		else {
			return par[x] = root(par[x]);
		}
	}
	//xとyが同じ集合に属すか否か
	bool same(int x, int y) {
		return(root(x) == root(y));
	}
	//xとyの属する集合を併合
	bool unite(int x, int y) {
		x = root(x);
		y = root(y);
		if (x == y)return false;//根が同じならもう併合済み
		//併合するときは"小さい方"を"大きい方"に併合させる
		if (size[x] < size[y]) {
			swap(x, y);
		}
		size[x] += size[y];
		par[y] = x;
		return true;
	}

	int getSize(int x) {
		return size[root(x)];
	}
};
int main() {
	cin >> n >> m;
	vector<P>p(m);
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		a--; b--;
		p[i] = make_pair(a, b);
	}
	ll ans = 0;
	for (int i = 0; i < m; i++) {
		union_find tree(n);
		tree.init(n);
		for (int j = 0; j < m; j++) {
			if (i != j) {
				tree.unite(p[j].first, p[j].second);
			}
		}
		if (!tree.same(p[i].first, p[i].second)) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}