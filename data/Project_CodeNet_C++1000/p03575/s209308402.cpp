#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define dup(x,y) (((x)+(y)-1)/(y))
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const double EPS = 1e-10;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

struct UnionFind {
	vector<int> par, siz;
	UnionFind(int n): par(n), siz(n,1) {
		rep(i,n) par[i] = i;
	}
	int find(int x) {
		return par[x] == x ? x: par[x] = find(par[x]);
	}
	bool unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) return false;
		siz[x] += siz[y];
		par[y] = x;
		return true;
	}
	int size(int x) {
		return siz[find(x)];
	}
};

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(m), b(m);
	rep(i,m) {
		cin >> a[i] >> b[i];
		a[i]--, b[i]--;
	}

	int ans = 0;
	rep(i,m) {
		UnionFind uf(n);
		rep(j,m) {
			if (i == j) continue;
			uf.unite(a[j], b[j]);
		}
		if (uf.size(a[i]) != n || uf.size(b[i]) != n) ans++;
	}
	cout << ans << endl;
}