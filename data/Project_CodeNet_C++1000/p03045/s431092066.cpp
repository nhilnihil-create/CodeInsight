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

int dsu[100005];

int dfind(int u) { return dsu[u] < 0 ? u : dsu[u] = dfind(dsu[u]); }
void dmerge(int u, int v) {
	u = dfind(u), v = dfind(v);
	if (u == v) return;
	dsu[u] += dsu[v];
	dsu[v] = u;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n, m; read(n, m);

	rep(i, 0, 100005) dsu[i] = -1;
	rep(i, 0, m) {
		int x, y, z; read(x, y, z);
		dmerge(x, y);
	}
	int ans = 0;
	rep(i, 1, n + 1) if (dfind(i) == i) ans++;
	die(ans);
}
