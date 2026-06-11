#include <queue>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, M; string S;
	cin >> N >> M >> S;
	vector<vector<int> > G(N);
	vector<int> rc(N), bc(N);
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b; --a, --b;
		G[a].push_back(b);
		G[b].push_back(a);
		if (S[b] == 'A') ++rc[a];
		else ++bc[a];
		if (S[a] == 'A') ++rc[b];
		else ++bc[b];
	}
	int cnt = 0;
	queue<int> que;
	for (int i = 0; i < N; ++i) {
		if (rc[i] == 0 || bc[i] == 0) {
			que.push(i);
		}
	}
	while (!que.empty()) {
		int u = que.front(); que.pop();
		++cnt;
		for (int i : G[u]) {
			if (rc[i] >= 1 && bc[i] >= 1) {
				if (S[u] == 'A') --rc[i];
				else --bc[i];
				if (rc[i] == 0 || bc[i] == 0) {
					que.push(i);
				}
			}
		}
	}
	cout << (cnt != N ? "Yes\n" : "No\n");
	return 0;
}