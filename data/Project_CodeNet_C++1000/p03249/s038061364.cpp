#include <bits/stdc++.h>
#include <tr1/unordered_map>

#define For(i, l, r) for (int i = l; i <= r; ++ i)
#define Forr(i, r, l) for (int i = r; i >= l; -- i)
#define Travel(i, u) for (int i = beg[u], v = to[i]; i; v = to[i = nex[i]])

using namespace std;

typedef long long ll;

inline void File() {
	freopen("f.in", "r", stdin);
	freopen("f.out", "w", stdout);
}

const int N = 1e5 + 10;
int e = 1, beg[N], nex[N << 1], to[N << 1], n;
int ansu[N], ansv[N];
ll sz[N], tmp, dis[N];

struct node { ll v; int id; } P[N];
inline bool cmp(const node &a, const node &b) { return a.v > b.v; }

tr1::unordered_map<ll, int> mp;

inline void add(int x, int y) {
	to[++ e] = y, nex[e] = beg[x], beg[x] = e;
}

inline void dfs1(int u, int l, int rt) {
	dis[rt] += l;
	Travel(i, u) dfs1(v, l + 1, rt);
}

inline void dfs2(int u) {
	Travel(i, u) dis[v] = dis[u] - (sz[v] * 2 - n), dfs2(v);
}

int main() {

	scanf("%d", &n);
	For(i, 1, n) {
		scanf("%lld", &P[i].v); 
		P[i].id = i, mp[P[i].v] = i, sz[i] = 1;
	}

	sort(P + 1, P + 1 + n, cmp);

	for (int i = 1, u, v; i < n; ++ i) {
		u = P[i].id, tmp = P[i].v + 2 * sz[u] - n;
		
		if (n <= sz[u] << 1) return puts("-1"), 0;
		if (!mp.count(tmp)) return puts("-1"), 0;
		
		v = mp[tmp], ansu[i] = u, ansv[i] = v;
		add(v, u), sz[v] += sz[u];
	}	

	int rt = P[n].id; dfs1(rt, 0, rt), dfs2(rt);

//	For(i, 1, n) cout << P[i].id << ' '; cout << endl;
//	For(i, 1, n) cout << P[i].v << ' ' << dis[P[i].id] << endl;
	For(i, 1, n) if (dis[P[i].id] ^ P[i].v) return puts("-1"), 0;
	
	For(i, 1, n - 1) printf("%d %d\n", ansu[i], ansv[i]);

	return 0;
}

