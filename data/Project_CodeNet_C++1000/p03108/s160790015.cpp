#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<int, int> P;
constexpr auto INF = INT_MAX/2;
constexpr auto LINF = 5000000000000000;
constexpr auto MOD = 1000000007;

struct UnionFind {

	vi data;

	UnionFind(int n = 0) {
		data.assign(n, -1);
	}

	int find(int k) {
		if (data[k] < 0) return k;
		return data[k] = find(data[k]);
	}
	bool unite(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) return false;
		if (data[x] > data[y]) swap(x, y);
		data[x] += data[y];
		data[y] = x;
		return true;
	}
	bool same(int x, int y) { return find(x) == find(y); }
	int size(int k) { return -data[find(k)]; }

};

int main() {

	int n, m;
	cin >> n >> m;

	vi a(m), b(m);

	rep(i, m) {
		cin >> a[i] >> b[i];
		a[i]--;b[i]--;
	}

	UnionFind uf(n);

	ll e = n * ((ll)n - 1) / 2;
	V<ll>ans(m);

	rep(i, m) {
		ans[m - 1 - i] = e;
		if (!uf.same(a[m - 1 - i], b[m - 1 - i])) {
			e -= (ll)uf.size(a[m - 1 - i]) * uf.size(b[m - 1 - i]);
			uf.unite(a[m - 1 - i], b[m - 1 - i]);
		}
	}

	rep(i, m)cout << ans[i] << endl;

}