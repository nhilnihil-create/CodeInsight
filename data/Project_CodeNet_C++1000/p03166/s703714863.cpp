#include<bits/stdc++.h>
using namespace std;
void topoSort(vector<vector<int>>& graph,int u,vector<bool>& visited,stack<int>& st) {
	visited[u] = true;
	for(int i=0;i<graph[u].size();i++) {
		if(!visited[graph[u][i]]) {
			topoSort(graph,graph[u][i],visited,st);
		}
	}
	st.push(u);
}
int main() {
	int n,m;
	cin>>n>>m;
	vector<vector<int>> graph(n,vector<int>(0));
	for(int i=0;i<m;i++) {
		int x,y;
		cin>>x>>y;
		graph[x-1].push_back(y-1);
	}
	stack<int> s;
	vector<bool> visited(n,false);
	for(int i=0;i<n;i++) {
		if(!visited[i]) {
			topoSort(graph,i,visited,s);
		}
	}
	vector<int> topo;
	while(!s.empty()) {
		topo.push_back(s.top());
		s.pop();
	}
	vector<int> dist(n,0);
	for(int i=0;i<n;i++) {
		int u = topo[i];
		for(int j=0;j<graph[u].size();j++) {
			if(dist[graph[u][j]] < (dist[u] + 1)) {
				dist[graph[u][j]] = dist[u] + 1;
			}
		}
	}
	int mxdist = 0;
	for(int i=0;i<n;i++) {
		mxdist = max(mxdist,dist[i]);
	}
	cout<<mxdist;
}