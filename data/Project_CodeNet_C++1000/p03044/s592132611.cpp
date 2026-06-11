#include <bits/stdc++.h>
using namespace std;

// Inserted snippets: io, root
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
// End snippets

vector<pii> g[100005];
int c[100005];

void dfs(int n, int p = -1) {
	for (auto q : g[n]) if (q.first != p) {
		c[q.first] = c[n] ^ (q.second & 1);
		dfs(q.first, n);
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n; read(n);
	rep(i, 1, n) {
		int u, v, w; read(u, v, w);
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}

	dfs(1);

	rep(i, 1, n + 1) write(c[i]);
}
