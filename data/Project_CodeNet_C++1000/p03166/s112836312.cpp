#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	vector<int> adj[n+1];
	vector<int> indegree(n+1, 0);

	for(int i=0;i<m;i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		indegree[v]++;
	}
	
	vector<int> dist(n+1, INT_MIN);
	vector<bool> visited(n+1, false);
	queue<int> q;
	for(int i=1;i<=n;i++){
		if(indegree[i]  == 0){
			q.push(i);
			dist[i] = 0;
		}
	}

	while(!q.empty()){
		int cur = q.front();
		q.pop();
		visited[cur] = true;

		for(int i: adj[cur]){
			if(!visited[i]){
				if(dist[i] < dist[cur] + 1){
					dist[i] = dist[cur] + 1;
				}
				if(--indegree[i] == 0){
					q.push(i);
				}
			}
		}
	}
	
	cout << *max_element(dist.begin(), dist.end());
	return 0;
}