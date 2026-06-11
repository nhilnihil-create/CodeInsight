#include <bits/stdc++.h>
#define newl "\n"
using namespace std;
using lli = long long int;
using vvint = vector <vector <int>>;
const int mod = 1e9 + 7;

const int N = 2e5 + 1;

void dfs(int s,vvint &adj,vector <bool> &vis){
	vis[s] = 1;
	for(int u : adj[s]){
		if(!vis[u]) dfs(u,adj,vis);
	}
	return;
}

void solve(){
	int n,m;
	cin >> n >> m;
	vector <pair <int,int>> p(m);
	for(int i = 0;i < m;++i){
		int a,b;
		cin >> a >> b;
		--a,--b;
		p[i] = {a,b};
	}
	int out = 0;
	for(int i = 0;i < m;++i){
		vvint adj(n);
		for(int j = 0;j < m;++j){
			if(j == i) continue;
			adj[p[j].first].push_back(p[j].second);
			adj[p[j].second].push_back(p[j].first);
		}
		vector <bool> vis(n,0);
		dfs(0,adj,vis);
		for(int i = 0;i < n;++i){
			if(!vis[i]){
				++out;
				break;
			}
		}
	}
	cout << out << newl;
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(10);
	#ifdef EXECUTE_LOCALLY
		   freopen("in.txt","r",stdin);
	#endif
	int t = 1;
	//cin >> t;
	while(t--) solve();
	#ifdef EXECUTE_LOCALLY
    	cout << setprecision(3) << "program time: " << (double)clock() / CLOCKS_PER_SEC << newl;
	#endif
	return 0;
}
