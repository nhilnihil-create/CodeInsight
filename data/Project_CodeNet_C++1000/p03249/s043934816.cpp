#include <bits/stdc++.h>

typedef long long s64; 
typedef std::pair<int, int> pii; 

template <class T>
inline void read(T &x) {
	static char ch; 
	while (!isdigit(ch = getchar())); 
	x = ch - '0'; 
	while (isdigit(ch = getchar()))
		x = x * 10 + ch - '0'; 
}

inline void invalid() {
	puts("-1"); 
	exit(0); 
}

const int MaxN = 1e5 + 5;  

int n; 
int sze[MaxN]; 
bool vis[MaxN]; 

s64 d[MaxN], c[MaxN];
std::vector<pii> ans; 
std::map<s64, int> pos; 

int fa[MaxN]; 
std::vector<int> adj[MaxN]; 

inline void addEdge(int u, int v) {
	sze[u] += sze[v]; 
	adj[u].push_back(v); 
	ans.push_back(pii(u, v)); 
}

inline void dfs(int u) {
	for (int v : adj[u]) {
		dfs(v); 
		c[u] += c[v] + sze[v]; 
	}
}

bool check() {
	int G = pos[d[n]]; 
	return dfs(G), c[G] == d[n]; 
}

int main() {
#ifdef orzczk
	freopen("tree.in", "r", stdin); 
#endif
	
	read(n); 
	for (int i = 1; i <= n; ++i) {
		read(d[i]); 
		sze[i] = 1; 
		pos[d[i]] = i; 
	}
	std::sort(d + 1, d + n + 1, std::greater<s64>()); 

	for (int i = 1; i < n; ++i) {
		int v = pos[d[i]], u; 
		s64 faD = d[i] - n + 2 * sze[v]; 

		vis[v] = true; 
		if (!pos.count(faD) || vis[u = pos[faD]]) {
			invalid(); 
		}
		
		addEdge(u, v); 
	}

	if (check()) {
		for (int i = 0; i < n - 1; ++i) {
			printf("%d %d\n", ans[i].first, ans[i].second); 
		}
	} else {
		invalid(); 
	}

	return 0; 
}