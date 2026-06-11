#include"bits/stdc++.h"

using namespace std;

#define MAX 200002

int n;
vector<int> g[MAX];

int dist[MAX];
queue<int> q;

int bfs(int b) {
	memset(dist, -1, sizeof(dist));
	dist[b] = 1;
	q.push(b);
	while (!q.empty()) {
		b = q.front();
		q.pop();
		for (int go : g[b]) {
			if (dist[go] == -1) {
				q.push(go);
				dist[go] = dist[b] + 1;
			}
		}
	}
	return b;
}

int z[MAX];

int main() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int mx=dist[bfs(bfs(0))];
	z[0] = 0;
	for (int i = 1; i <= mx; i++) {
		if (i <= 2) {
			if (z[i - 1] == 0) {
				z[i] = 1;
			}
			else {
				z[i] = 0;
			}
			continue;
		}
		if (z[i - 1] == 0) {
			z[i] = 1;
		}
		if (z[i - 2] == 0) {
			z[i] = 1;
		}
	}
	if (z[mx]) {
		puts("First");
	}
	else {
		puts("Second");
	}

	return 0;
}