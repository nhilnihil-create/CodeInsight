#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int N;
vector <int> adj[MAXN];
int path, node;

void dfs(int x, int p, int d) {
	if (d > path) {
		path = d;
		node = x;
	}
	for (auto it : adj[x])
		if (it != p)
			dfs(it, x, d + 1);
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i < N; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	dfs(1, 0, 0);
	path = 0;
	dfs(node, 0, 0);
	
	puts(path % 3 == 1 ? "Second" : "First");
	
	return 0;
}