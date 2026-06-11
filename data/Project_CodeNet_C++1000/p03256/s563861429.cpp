#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

vector<int> adj[N];
int n, m;
string s;
int cnt[N][2]; // 0=>A, 1=>B
bool vis[N];

void bfs() {
	queue<int> Q;
	for (int i = 0; i < n; i++) {
		if (cnt[i][0] == 0 || cnt[i][1] == 0) {
			Q.push(i); // invalid nodes
			vis[i] = 1;
		}
	}
	while (!Q.empty()) {
		int cur = Q.front(); // this node will be removed
		Q.pop();
//		for (int i  = 0; i < adj[cur].size(); i++) {
//			int to = adj[cur][i];
//		}
		for (auto to : adj[cur]) {
			if (vis[to])
				continue;
			int curColor = s[cur] - 'A';
			cnt[to][curColor]--;
			if (cnt[to][0] == 0 || cnt[to][1] == 0) {
				Q.push(to);
				vis[to] = 1;
			}
		}
	}
}

int main() {
	cin >> n >> m;
	cin >> s;
	for (int i = 0; i < m; i++) {
		int f, t;
		cin >> f >> t;
		f--, t--;
		adj[f].push_back(t);
		adj[t].push_back(f);
		cnt[f][s[t] - 'A']++;
		cnt[t][s[f] - 'A']++;
	}
	bfs();
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			puts("Yes");
			return 0;
		}
	}
	puts("No");
	return 0;
}
