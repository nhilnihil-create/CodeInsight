#include<bits/stdc++.h>
using namespace std;

int N,M;
int place;

vector<vector<int>> adj_list;
vector<int> t,visited;


void dfs(int i) {
	visited[i]=true;
	for (int u:adj_list[i])
	{
		if(!visited[u])
			dfs(u);
	}
	t[place] = i;
	place--;
}

void top_sort() {
	t.resize(N+1);
	visited.assign(N+1,0);

	place = N;
	for(int i=1;i<=N;++i) {
		if(!visited[i]) 
			dfs(i);
	}
}


int main() {

	cin>>N>>M;
	adj_list.resize(N+1);
	for (int i = 0; i < M; ++i)
	{
		int x,y;
		cin>>x>>y;
		adj_list[x].push_back(y);
	}

	top_sort();

	vector<int> path(N+1);


	for (int i = N; i >= 0; --i)
	{
		int node = t[i];
		if(adj_list[node].empty()) {
			path[node] =0;
		}
		else {
			for(int u:adj_list[node]) {
				path[node] = max(path[node],path[u]+1);
			}
		}
	}

	cout<<*max_element(path.begin(),path.end());




	return 0;
}