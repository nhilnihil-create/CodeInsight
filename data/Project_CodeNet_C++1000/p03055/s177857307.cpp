#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void print(vector<int> &A) {
	for (int i = 0; i < A.size(); i++)
		printf("%d ", A[i]);
	printf("\n");
}

void print_matrix(vector< vector<int> > &m) {
	for (int i = 0; i < m.size(); i++)
		print(m[i]);
}

class graph {
public:
	int n;
	vector< vector<int> > adj;

	graph(int _n) {
		n = _n;
		adj = vector< vector<int> >(n, vector<int>());
	}

	void add_edge(int u, int v) {
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	void bfs(int root, vector<int> &distance) {
		queue< pair<int, int> > q;
		q.push(make_pair(root, 0));
		distance[root] = 0;

		while ( !q.empty() ) {
			pair<int, int> curr = q.front();
			q.pop();

			int u = curr.first;
			int d = curr.second;

			for (int v : adj[u]) {
				if ( distance[v] == INT_MAX ) {
					distance[v] = 1 + d;
					q.push(make_pair(v, 1 + d));
				}
			}
		}
	}

	int diameter() {
		vector<int> distance(n, INT_MAX);

		int root = 0;
		bfs(root, distance);
		int farther = root;
		for (int i = 0; i < n; i++) {
			if (distance[i] > distance[farther])
				farther = i;
		}
		// print(distance);

		for (int i = 0; i < n; i++)
			distance[i] = INT_MAX;

		root = farther;
		bfs(root, distance);
		farther = root;
		for (int i = 0; i < n; i++) {
			if (distance[i] > distance[farther])
				farther = i;
		}
		// print(distance);

		return distance[farther];
	}
};

int main() {
	int n;
	cin >> n;

	graph *g = new graph(n);

	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		g->add_edge(u - 1, v - 1);
	}

	int d = g->diameter();
	// cout << d << endl;

	string ans = ((d - 1) % 3 == 0 ? "Second" : "First");
	cout << ans << endl;

	return 0;
}