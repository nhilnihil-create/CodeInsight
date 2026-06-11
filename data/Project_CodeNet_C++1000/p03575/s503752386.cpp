#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> graph[55];
bool used[55];
vector<vector<int>> comps;
int x = 0, y = 0;
void dfs(int v) {
    used[v] = true;
    comps.back().push_back(v);

    for (int u: graph[v]) {
    	if (v == x && u == y) continue;
        if (!used[u]) {
            dfs(u);
        }
    }
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (auto f : graph[i]) {
			comps.clear();
			x = i;
			y = f;
			for (int i = 0; i < n; i++) {
				used[i] = false;
			}
			for (int i = 0; i < n; i++) {
        		if (!used[i]) {
            		comps.push_back(vector<int>());   //добавляем в comps новый пустой вектор,
            		dfs(i);
        		}
    		}
    		if (comps.size() > 1) {
    			cnt++;
    		}
		}
	}
	cout << cnt;
	return 0;
}