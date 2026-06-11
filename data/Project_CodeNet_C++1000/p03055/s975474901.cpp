#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> shortest_path(int N, int src, vector<vector<int> >& G) {
	vector<int> dist(N, -1);
	dist[src] = 0;
	queue<int> que;
	que.push(src);
	while (!que.empty()) {
		int u = que.front(); que.pop();
		for (int i : G[u]) {
			if (dist[i] == -1) {
				dist[i] = dist[u] + 1;
				que.push(i);
			}
		}
	}
	return dist;
}
int main() {
	int N;
	cin >> N;
	vector<vector<int> > G(N);
	for (int i = 0; i < N - 1; ++i) {
		int a, b;
		cin >> a >> b; --a, --b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	vector<int> d1 = shortest_path(N, 0, G);
	vector<int> d2 = shortest_path(N, max_element(d1.begin(), d1.end()) - d1.begin(), G);
	cout << (*max_element(d2.begin(), d2.end()) % 3 == 1 ? "Second" : "First") << endl;
	return 0;
}