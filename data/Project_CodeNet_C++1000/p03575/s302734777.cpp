#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<typename H> bool chmin(H& v1, const H v2) { if (v1 > v2) { v1 = v2; return true; } return false; }
template<typename H> bool chmax(H& v1, const H v2) { if (v1 < v2) { v1 = v2; return true; } return false; }
template<typename H> void read(H& head) { cin >> head; }
template<typename H, typename ...T> void read(H& head, T& ...tail) { cin >> head; read(tail...); }
template<typename H> void write(H head) { cout << head << '\n'; }
template<typename H, typename ...T> void write(H head, T ...tail) { cout << head << " "; write(tail...); }
template<typename ...T> void die(T ...tok) { write(tok...); exit(0); }

struct Dsu {
	int dsu[55];
	Dsu() { rep(i, 0, 55) dsu[i] = -1; }
	int find(int x) {
		return dsu[x] < 0 ? x : dsu[x] = find(dsu[x]);
	}
	void merge(int u, int v) {
		u = find(u), v = find(v);
		if (u == v) return;
		if (-dsu[u] > -dsu[v]) swap(u, v);
		dsu[u] += dsu[v];
		dsu[v] = u;
	}
} dsu;

int a[2505], b[2505];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n, m; read(n, m);
	rep(i, 0, m) read(a[i], b[i]);
	int ans = 0;
	rep(i, 0, m) {
		dsu = Dsu();
		rep(j, 0, m) if (j != i) dsu.merge(a[j], b[j]);
		if (dsu.dsu[dsu.find(1)] != -n) ans++;
	}
	die(ans);
}
