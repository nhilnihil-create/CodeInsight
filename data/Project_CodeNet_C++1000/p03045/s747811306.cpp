#include <iostream>
#include <vector>
#include <stack>
using namespace std;
const int N_MAX = 100000;

vector<vector<int>> g;

int group[N_MAX];
int num_of_groups;
int size_of_group[N_MAX];

void dfs(int s, int k) {
	stack<int> st;
	st.push(s);
	group[s] = k;
	size_of_group[k]++;
	while (!st.empty()) {
		int v = st.top(); st.pop();
		for (int i : g[v]) {
			if (group[i] != -1) continue;
			st.push(i);
			group[i] = k;
			size_of_group[k]++;
		}
	}
	return;
}

void connected_component_decomposition() {
	const int V = g.size();
	num_of_groups = 0;
	fill(group, group+V, -1);
	for (int i = 0; i < V; i++) {
		if (group[i] == -1) {
			dfs(i, num_of_groups);
			num_of_groups++;
		}
	}
	return;
}

int main() {
	int n, m;
	cin >> n >> m;
	g.assign(n, vector<int>());
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		x--; y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	connected_component_decomposition();
	cout << num_of_groups << endl;
	return 0;
}