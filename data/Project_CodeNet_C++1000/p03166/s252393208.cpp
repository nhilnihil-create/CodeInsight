#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> edges;
vector<int> d;
vector<int> indegree;
vector<bool> visited;

void dfs(int n){
	visited[n]=true;
	for(auto e:edges[n]){
		if(!visited[e]){
			d[e]=max(d[e],1+d[n]);
			indegree[e]--;
		}
		if(indegree[e]==0){
			dfs(e);
		}
	}
}

int main(){
	int n,m;cin>>n>>m;
	edges.assign(n+1,vector<int>());
	d.assign(n+1,0);
	indegree.assign(n+1,0);
	visited.assign(n+1,false);
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		edges[u].push_back(v);
		++indegree[v];
	}
	for(int i=1;i<=n;i++){
		if(indegree[i]==0 && !visited[i]){
			dfs(i);
		}
	}
	int mm=0;
	for(int i=1;i<=n;i++)
		mm=max(mm,d[i]);

	cout<<mm<<endl;
		
}