#include <bits/stdc++.h>
#define MAX_N 100000
using namespace std;
typedef long long lnt;
template <class T> inline void read(T &x) {
	x = 0; int c = getchar(), f = 1;
	for (; !isdigit(c); c = getchar()) if (c == 45) f = -1;
	for (; isdigit(c); c = getchar()) (x *= 10) += f*(c-'0');
}
int n, sz[MAX_N+5]; lnt s[MAX_N+5], tot;
map <lnt, int> id; vector <int> G[MAX_N+5];
void DFS(int u, int d) {tot += d; for (int v : G[u]) DFS(v, d+1);}
int main() {
	read(n);
	for (int i = 1; i <= n; i++)
		read(s[i]), id[s[i]] = i, sz[i] = 1;
	sort(s+1, s+n+1, greater<lnt>());
	for (int i = 1; i < n; i++) {
		int u = id[s[i]];
		lnt sf = s[i]-n+2*sz[u];
		if (sf >= s[i] || !id.count(sf))
			return puts("-1"), 0;
		int f = id[sf];
		sz[f] += sz[u];
		G[f].push_back(u);
	}
	DFS(id[s[n]], 0);
	if (tot != s[n])
		return puts("-1"), 0;
	for (int u = 1; u <= n; u++)
		for (int v : G[u]) printf("%d %d\n", u, v);
	return 0;
}