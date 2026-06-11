#include<bits/stdc++.h>

#define LL long long
#define RG register

using namespace std;
template<class T> T gi() {
	T x = 0; bool f = 0; char c = getchar();
	while (c != '-' && (c < '0' || c > '9')) c = getchar();
	if (c == '-') f = 1, c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return f ? -x : x;
}
const int N = 1e5 + 10;
int p[N], siz[N], X[N], Y[N], fa[N];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
LL D[N];
map<LL, int> M;
vector<int> e[N];
bool cmp(int x, int y) { return D[x] > D[y]; }
LL res;
void dfs(int u, int ff) {
	siz[u] = 1;
	for (auto v : e[u])
		if (v != ff) {
			dfs(v, u);
			res += siz[v];
			siz[u] += siz[v];
		}
}
int main() {
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	int n = gi<int>();
	for (int i = 1; i <= n; i++)
		D[i] = gi<LL>(), M[D[i]] = i, p[i] = i;
	sort(p + 1, p + 1 + n, cmp);
	for (int i = 1; i <= n; i++) siz[i] = 1, fa[i] = i;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		int x = p[i];		
		if (M.find(D[x] - n + 2 * siz[x]) == M.end()) continue;
		int y = M[D[x] - n + 2 * siz[x]];
		if (find(x) == find(y)) continue;
		fa[find(y)] = find(x);
		siz[y] += siz[x]; X[++cnt] = x; Y[cnt] = y;
		e[x].push_back(y); e[y].push_back(x);
	}
	dfs(1, 0);
	if (cnt < n - 1 || res != D[1])
		puts("-1");
	else
		for (int i = 1; i < n; i++)
			printf("%d %d\n", X[i], Y[i]);	
	return 0;
}
