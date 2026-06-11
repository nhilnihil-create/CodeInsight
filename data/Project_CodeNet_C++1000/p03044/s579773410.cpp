#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void dpf(int n, const vector<vector<pair<int, int>>>& graph, vector<int>& seen) {
	for (int i = 0; i < graph[n].size(); i++) {
		if (seen[graph[n][i].first] != -1) continue;
		if (graph[n][i].second % 2 == 0) {
			seen[graph[n][i].first] = seen[n];
			dpf(graph[n][i].first, graph, seen);
		}
		else {
			seen[graph[n][i].first] = abs(seen[n] - 1);
			dpf(graph[n][i].first, graph, seen);
		}
	}
}

int main() {
	int N;
	cin >> N;
	vector<vector<pair<int, int>>> graph(N);
	int u, v, w;
	for (int i = 0; i < N - 1; i++) {
		cin >> u >> v >> w;
		graph[u - 1].push_back(make_pair(v - 1, w));
		graph[v - 1].push_back(make_pair(u - 1, w));
	}
	vector<int> seen(N, -1);
	seen[0] = 0;
	dpf(0, graph, seen);
	for (int i = 0; i < N; i++) {
		cout << seen[i] << endl;
	}
}