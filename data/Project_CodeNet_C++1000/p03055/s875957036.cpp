#include <bits/stdc++.h>
using namespace std;

int i,root,depth[200005]={0},mmax=0;
vector<int> g[200005];
bool used[200005]={0};

void dfs(int v){
	used[v]=true;
	for(int j=0;j<g[v].size();j++){
		if(!used[g[v][j]]){
			depth[g[v][j]]=depth[v]+1;
			dfs(g[v][j]);
		}
	}
}
 
int main (void){
	int n,a,b;
	cin >> n;
	for(i=1;i<n;i++) {
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	depth[1]=0;
	dfs(1);
	mmax=-1;
	for(i=1;i<=n;i++){
		if(mmax<depth[i]){
			mmax=depth[i];
			root=i;
		}
	}
	for(i=1;i<=n;i++) {
		used[i]=false;
		depth[i]=0;
	}
	depth[root]=0;
	dfs(root);
	mmax=-1;
	for(i=1;i<=n;i++){
		if(mmax<depth[i]){
			mmax=depth[i];
			root=i;
		}
	}
	if(mmax%3==1) cout << "Second" << endl;
	else cout << "First" << endl;
	return 0;
}
