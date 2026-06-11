#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
vector<pi>tree[100005];
bool visited[100005];
int color[100005];
void dfs(int curr){
	visited[curr] = true;
	for(int i=0; i<tree[curr].size(); i++){
		int nxt = tree[curr][i].first;
		int p = tree[curr][i].second;
		if(!visited[nxt]){
			if(p) color[nxt] = !color[curr];
			else color[nxt] = color[curr];
			dfs(nxt);
		}
	}
}
int main(){
	int n;
	cin>>n;
	for(int i=1; i<n; i++){
		int a,b,w;
		cin>>a>>b>>w;
		tree[a].push_back(pi(b,w%2));
		tree[b].push_back(pi(a,w%2));
	}
	dfs(1);
	for(int i=1; i<=n; i++) cout<<color[i]<<'\n';
}