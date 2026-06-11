#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector <int> edges[N];
int dist[N];
int in_degree[N];
bool visited[N];
void dfs(int now){
	visited[now] = 1;
	for (auto i : edges[now]){
		if (!visited[i]){
			--in_degree[i];
			//cout << ">" << now << " " << i << "<\n";
			dist[i] = max(dist[now]+1, dist[i]);
			if (in_degree[i] == 0)
				dfs(i);
			//visited[i] = 0;
		}
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		edges[x].emplace_back(y);
		in_degree[y]++;
	}
	for (int i = 1; i <= n; i++){
		if (!visited[i] && in_degree[i] == 0){
			dfs(i);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++){
		//cout << dist[i] << " " <<i << "@\n";
		ans = max(dist[i], ans);
	}
	cout << ans <<"\n";
}
