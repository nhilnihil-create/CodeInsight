#include <bits/stdc++.h>
using namespace std;

int n, m, l, r, d1;
vector<pair<int,int>> e[100004];
bool visited[100004];
long long d[100004];
bool ok;
void dfs(int here){
	visited[here] = true;
	for(auto i : e[here]){
		int there = i.first;
		int dist = i.second;
		if(!visited[there]){	
			d[there] = d[here] + dist;
			dfs(there);
		}
		else
			if(d[here]+dist != d[there])	
				ok = false;
		}
	return;
}

int main() {
	cin>>n>>m;
	while(m--){
		cin>>l>>r>>d1;
		e[l].push_back({r,d1});
		e[r].push_back({l,-d1});
	}
	ok = true;
	memset(visited,false,sizeof(visited));
	memset(d,0,sizeof(d));
	for(int i = 1; i<=n;i++){
		if(visited[i])	continue;
		d[i] = 0;
		dfs(i);
	}
	cout<<(ok? "Yes" : "No");
	return 0;
}