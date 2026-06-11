#include <bits/stdc++.h>
#define maxn 200005
using namespace std;
int n;
vector<int> g[maxn];
int dep[maxn];
int len, id;
bool SG[maxn];
void dfs(int x) {
	if (dep[x] > len) len = dep[x], id = x;
	for (int i = 0; i < g[x].size(); i++) {
		if (!dep[g[x][i]]) {
			dep[g[x][i]] = dep[x] + 1;
			dfs(g[x][i]);
		}
	}
}
int main() {
	scanf("%d", &n);
	memset(dep, 0, sizeof(dep));
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dep[1] = 1;
	dfs(1);
	memset(dep, 0, sizeof(dep));
	dep[id] = 1;
	dfs(id);
	SG[1] = 1; SG[2] = 0;
	for (int i = 3; i <= n; i++) {
		SG[i] = !(SG[i - 1] & SG[i - 2]);
		//printf("%d ", SG[i]);
	}
	//puts("");
	if (SG[len]) printf("First\n");
	else printf("Second\n");
	return 0;
}