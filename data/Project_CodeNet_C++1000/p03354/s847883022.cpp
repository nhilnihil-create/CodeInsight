#include <cmath>
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<set>
#include<bitset>
#include<iomanip>
#include<stack>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
ll n, m;
int p[100005];
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

//union_find tree;
//tree.init(); //これで初期化
//tree.unite(a,b) //aとbのグループを併合
//tree.same(a,b) //aとbが同じグループか(trueかfalse)
int main(void) {
	cin >> n >> m;
	union_find tree(n);
	
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		a--; b--;
		if (!tree.same(a, b)) {
			tree.unite(a, b);
		}
	}
	ll count = 0;
	for (int i = 0; i < n; i++) {
		if (tree.same(p[i]-1, i)) {
			count++;
		}
	}
	cout << count << endl;
	return 0;
}