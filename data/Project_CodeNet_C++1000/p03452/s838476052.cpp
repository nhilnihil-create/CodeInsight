#include<bits/stdc++.h>

using std::vector;
struct edge {
	int to;
	int cost;
};
int dist[100100];
vector<edge> G[100100];
bool chk[100100];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int l, r, d;
		scanf("%d%d%d", &l, &r, &d);
		G[l].push_back({ r,d });
		G[r].push_back({ l,-d });
	}

	std::queue<int> que;
	std::queue<int> que2;
	for (int i = 1; i <= n; i++)que2.push(i);
	while (!que2.empty()) {
		int tmp = que2.front();
		que2.pop();
		if (!chk[tmp]) {
			que.push(tmp);
			chk[tmp] = true;
		}
		while (!que.empty()) {
			int idx = que.front();
			que.pop();

			for (edge e : G[idx]) {
				if (!chk[e.to]) {
					chk[e.to] = true;
					dist[e.to] = dist[idx] + e.cost;
					que.push(e.to);
				}
				if (dist[e.to] != dist[idx] + e.cost) {
					printf("No");
					return 0;
				}
			}
		}
	}
	printf("Yes");
	return 0;
}