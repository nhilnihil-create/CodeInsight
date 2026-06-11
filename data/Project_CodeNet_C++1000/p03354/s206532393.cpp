#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	int n, m;
	cin >> n >> m;
	int p[n];
	for (int i = 0; i < n; i++)
		cin >> p[i];
	vector<vector<int>> G(n);
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		G[x-1].push_back(y-1);
		G[y-1].push_back(x-1);
	}

	vector<vector<int>> groups;

	set<int> todo;
	vector<bool> visited(n, false);
	for (int i = 0; i < n; i++)
		todo.insert(i);
	queue<int> q;
	while (!todo.empty()) {
		q.push(*todo.begin());
		groups.resize(groups.size()+1);
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			if (visited[v])
				continue;
			visited[v] = true;
			todo.erase(v);
			groups.back().push_back(v);
			for (auto e : G[v]) {
				if (!visited[e])
					q.push(e);
			}
		}
	}
	//for (auto e : groups) {
	//	for (auto f : e) {
	//		printf("%d ", f);
	//	}
	//	cout << endl;
	//}
	
	int count = 0;
	for (auto e : groups) {
		set<int> s;
		for (auto f : e) {
			s.insert(p[f]);
		}
		for (auto f : e) {
			if (s.find(f+1) != s.end()) {
				count++;
			}
		}
	}
	cout << count << endl;
	return 0;
}