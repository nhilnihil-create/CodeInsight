#include<iostream>
#include<bits/stdc++.h>

using namespace std;
vector<int> arr[100001];
bool vis[100001];
int dist[100001];


void dfs(int node){
	vis[node] = 1;

	for(auto child: arr[node]){
		if(vis[child] == 0)
			dfs(child);
		dist[node] = max(dist[node], 1+ dist[child]);

		
	}
}
int main(){
	//https://atcoder.jp/contests/dp/tasks/dp_g
	int n, m;
	cin >> n >> m;
	int a, b;
	for(int i=0;i<=n;i++){
		vis[i] = 0;
		dist[i] = 0;
		arr[i].clear();
	}
	for(int i=0;i<m;i++){
		cin >> a >> b;
		arr[a].push_back(b);

	}

	for(int i=1;i<=n;i++){
		if(vis[i] == 0)
			dfs(i);
	}
	int maxi = 0;
	for(int i=1;i<=n;i++){
		maxi  = max(maxi, dist[i]);
	}
	cout << maxi << endl;

	return 0;
}