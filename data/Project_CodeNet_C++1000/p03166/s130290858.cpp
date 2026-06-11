#include<bits/stdc++.h>
using namespace std;
int N, M, x, y;
vector <int> adj[100005];
int dis[100005];
using namespace std;
int dfs(int cur){
	if(dis[cur] != 1) return dis[cur];
	int maxtemp = 0;
	for(auto j : adj[cur]){
		maxtemp = max(maxtemp, dfs(j));
	}
	dis[cur] += maxtemp;
	return dis[cur];
}
int main(){
	scanf("%d%d", &N, &M);
	for(int i = 0 ; i<M ;  i++){
		scanf("%d%d", &x, &y);
		adj[x].push_back(y);
	}
	fill(dis,dis+N+1,1);
	int maxdis = 0;
	for(int i = 1 ; i<=N ; i++){
		maxdis = max(maxdis, dfs(i));
	}
	cout << maxdis -1 <<endl;
}