#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

int n, m, l, r, d, dist[100001], vis[100001];
vector<pi> adj[100001];

void dfs(int node){
	vis[node] = 1;
	for(auto it:adj[node]){
		if(vis[it.first] != -1){
			if(dist[it.first] != dist[node]+it.second){ cout << "No"; exit(0); }
			continue;
		}
		vis[it.first] = 1;
		dist[it.first] = dist[node]+it.second;
		dfs(it.first);
	}
}

int main(){
	memset(vis, -1, sizeof(vis));
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> l >> r >> d;
		adj[l].push_back(pi(r, d));
		adj[r].push_back(pi(l, -d));
	}
	for(int i = 1; i <= n; i++){
		if(vis[i] == -1) dfs(i);
	}
	cout << "Yes";
}