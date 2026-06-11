#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>

#include <bits/stdc++.h>
#include <cmath>
#include <limits>

using namespace std;
using Graph = vector<vector<int>>;

void dfs(int v, Graph g, vector<int> &seen){
	if(seen[v]==1) return;
	seen[v] = 1;

	for(auto nv : g[v]){
		if(seen[nv] == 1) continue;
		dfs(nv, g, seen);
	}
}

int isConnected(Graph g){
	vector<int> s;
	s.assign(g.size(), 0);
	dfs(0, g, s);
	int sum = 0;
	for(int i = 0; i < s.size(); i++){
		sum += s[i];
	}
	if(g.size() == sum){
		return 1;
	}
	else{
		return 0;
	}
}

int isBridge(Graph g, vector<pair<int, int>> v, int e){
	int a = v[e].first;
	int b = v[e].second;
	int i = 0;
	for(i = 0; i < g[a].size(); i++){
		if(g[a][i] == b){
			break;
		}
	}
	g[a].erase(g[a].begin() + i);
	for(i = 0; i < g[b].size(); i++){
		if(g[b][i] == a){
			break;
		}
	}
	g[b].erase(g[b].begin() + i);

	int ret = isConnected(g);
	if(ret==0){ 
		ret = 1;
	}
	else{
		ret = 0;
	}
	return ret;
}

int main(int argc, char* argv[]){
	int N, M;
	vector<pair<int, int>> edge;

	cin >> N >> M;
	Graph G(N);

	for(int i=1; i<=M; i++){
		int a, b;
		cin >> a >> b;
		a = a - 1; b = b - 1;
		edge.push_back( make_pair(a, b) );
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int ans = 0;
	for(int i=0; i<M; i++){
		ans += isBridge(G, edge, i);
	}
	cout << ans << endl;
	return 0;
}