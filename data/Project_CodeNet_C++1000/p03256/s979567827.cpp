#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = 2e5 + 25;
vector<int> g[N];
int vis[N][4];
string s;

bool dfs(int v, int i){
	if(vis[v][i] == 2)return false;
	if(vis[v][i] == 1)return true;
	vis[v][i] = 1;
	for(int u : g[v]){
		if(s[u] == 'A'){
			if(i == 0 && dfs(u, 1))return true;
			if(i == 3 && dfs(u, 0))return true;
		}else{
			if(i == 1 && dfs(u, 2))return true;
			if(i == 2 && dfs(u, 3))return true;
		}
	}
	vis[v][i] = 2;
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout<<setprecision(32);

	int n, m;
	cin>>n>>m>>s;
	for(int i = 0; i < m; i++){
		int u, v;
		cin>>u>>v;
		u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	memset(vis, 0, sizeof(vis));
	for(int i = 0; i < n; i++){
		if(s[i] == 'A' && vis[i][0] == 0 && dfs(i, 0)){
			cout<<"Yes\n";
			exit(0);
		}
	}
	cout<<"No\n";

	return 0;
}