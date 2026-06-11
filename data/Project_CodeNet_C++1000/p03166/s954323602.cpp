#include<bits/stdc++.h>
using namespace std;
const int INF=1e5+1;
int dist[INF];
bool visited[INF];
void dfs(vector<int> graph[],int node){
    visited[node]=true;
    for(int i=0;i<graph[node].size();i++){
        if(!visited[graph[node][i]]) dfs(graph,graph[node][i]);
        dist[node]=max(dist[node],1+dist[graph[node][i]]);

    }
}
int main(){
	int n,m;
	cin>>n>>m;
    vector<int> graph[n];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        graph[u-1].push_back(v-1);
    }
    for(int i=0;i<n;i++){
        if(!visited[i]) dfs(graph,i);
    }
    int maxPath=0;
	for(int i=0;i<n;i++){
        maxPath=max(maxPath,dist[i]);
    }
    cout<<maxPath;
	return 0;
}
