#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
typedef vector<ll> VI;
typedef vector<VI> VVI;
const ll MOD = 1000000007;
const ll INF = 1e18;
#define REP(i, n) for(int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

struct unionfind {
	vector<int> par, siz;
	unionfind(int N) : par(N), siz(N,1) {
		for (int i = 0; i < N; i++) par[i] = i;
	}
	int root(int x) {
		while(par[x] != x) x = par[x] = par[par[x]];
		return x;
	}
	void unite(int x, int y) {
		x = root(x); y = root(y);
		if (x == y) return;
		if (siz[x] < siz[y]) swap(x, y);
		siz[x] += siz[y];
		par[y] = x;
	}
	bool same(int x, int y) {
		return root(x) == root(y);
	}
	int size(int x) {
		return siz[root(x)];
	}
};

int main(){
	int n, m; cin >> n >> m;
	unionfind uf(n);
	int x, y, z;
	REP(i,m){
		cin >> x >> y >> z;
		x--; y--;
		uf.unite(x,y);
	}
	vector<bool> f(n,0);
	int ans=0;
	REP(i,n){
		int r=uf.root(i);
		if(!f[r]){
			f[r]=1;
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}