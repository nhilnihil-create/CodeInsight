#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 1e5+1;

vector<vector<int>> adj(N);
vector<bool> vu(N);

void dfs(int node){
	for (int i:adj[node]){
		if (!vu[i]){
			vu[i] = true;
			dfs(i);
		}
	}
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	for (int i=0; i<m; ++i){
		int a,b,z;
		cin >> a >> b >> z;
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}
	int ans = 0;
	for (int i=1; i<=n; ++i){
		if (!vu[i]){
			vu[i] = true;
			ans++;
			dfs(i);
		}
	}
	cout << ans;
	return 0;
}
