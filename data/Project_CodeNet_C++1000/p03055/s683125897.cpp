#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

typedef long long LL;
 
const int OO = 1e9;
const int MOD = 1e9 + 7;

class Task {
public:

	int n;
	vector<vector<int>> g;

	vector<int> bfs(int v) {
		vector<int> dist(n, -1);
		dist[v] = 0;
		
		queue<int> q;
		q.push(v);
		
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (int w: g[u]) {
				if (dist[w] == -1) {
					dist[w] = dist[u] + 1;
					q.push(w);
				}
			}
		}
		
		return dist;
	}
	
	int get_diam() {
		vector<int> dist;
		int v = 0;
		dist = bfs(v);
		for (int i = 0; i < n; ++i)
			if (dist[v] < dist[i])
				v = i;
		dist = bfs(v);
		for (int i = 0; i < n; ++i)
			if (dist[v] < dist[i])
				v = i;
		return dist[v];
	}

	void solve() {
		cin >> n;
		g.resize(n);
		for (int i = 1; i < n; ++i) {
			int u, v;
			cin >> u >> v;
			--u, --v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		
		int diam = get_diam() + 1;
		
		if (diam % 3 < 2)
			cout << "First\n";
		else
			cout << "Second\n";
	}
};
 
int32_t main() {
//~ #ifndef ONLINE_JUDGE
	//~ freopen("input.txt", "r", stdin);
//~ #endif
 
	Task *task = new Task();
	task->solve();
	return 0;
}
