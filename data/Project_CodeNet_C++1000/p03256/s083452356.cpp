#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n, m;
char s[N];
vector<int> adj[N];
int cnt[2][N];
int removed[N];

bool canRemove(int u) {
	return cnt[0][u] == 0 || cnt[1][u] == 0;
}

int main() {
	scanf("%d %d", &n, &m);
	scanf("%s", s + 1);
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		cnt[s[u] == 'A'][v]++;
		cnt[s[v] == 'A'][u]++;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (canRemove(i)) {
			q.push(i);
			removed[i] = 1;
		}
	}
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v : adj[u]) {
			if (removed[v]) {
				continue;
			}
			cnt[s[u] == 'A'][v]--;
			if (canRemove(v)) {
				removed[v] = 1;
				q.push(v);
			}
		}
	}
	int id = -1;
	for (int i = 1; i <= n; i++) {
		if (!removed[i]) {
			id = i;
			break;
		}
	}
	puts(id == -1 ? "No" : "Yes");
	return 0;
}	