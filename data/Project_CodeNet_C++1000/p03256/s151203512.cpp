#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int N, M;
char s[MAXN];
vector <int> adj[2 * MAXN];
int bio[2 * MAXN];

void add(int u, int v) {
	adj[u].push_back(v);
}

void load() {
	scanf("%d%d%s", &N, &M, s + 1);
	while (M--) {
		int a, b;
		scanf("%d%d", &a, &b);
		if (s[a] == s[b]) {
			add(2 * a - 1, 2 * b);
			add(2 * b - 1, 2 * a);
		}
		else {
			add(2 * a, 2 * b - 1);
			add(2 * b, 2 * a - 1);
		}
	}
}

bool dfs(int x) {
	if (bio[x])
		return 2 - bio[x];
	bio[x] = 1;
	for (auto it : adj[x])
		if (dfs(it))
			return true;
	bio[x] = 2;
	return false;
}

bool solve() {
	for (int i = 1; i <= 2 * N; i++)
		if (dfs(i))
			return true;
	return false;
}

int main() {
	load();
	puts(solve() ? "Yes" : "No");
	return 0;
}