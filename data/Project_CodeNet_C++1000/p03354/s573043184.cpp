
#include <iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;

const ll MOD_CONST = 1000000007;

struct UnionFind {

	vector<int> p;

	UnionFind(int n) :p(n) {
		for (int i = 0; i < n; i++) {
			p[i] = i;
		}
	}

	int root(int x) {
		if (p[x] == x) {
			return x;
		}
		p[x] = root(p[x]);
		return p[x];
	}

	void unite(int x, int y) {
		int rx = root(x);
		int ry = root(y);
		if (rx == ry) {
			return;
		}

		p[rx] = ry;
	}

	bool same(int x, int y) {
		return root(x) == root(y);
	}

};

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		p[i]--;
	}

	UnionFind uf(n);
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;

		uf.unite(x, y);
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (uf.same(p[i], i)) {
			cnt++;
		}
	}
	cout << cnt << endl;
}  

