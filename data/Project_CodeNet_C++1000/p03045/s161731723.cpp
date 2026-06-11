#include <bits/stdc++.h>
#define newl "\n"
using namespace std;
using lli = long long int;
using vvint = vector <vector <int>>;
const int mod = 1e9 + 7;

const int N = 2e5 + 1;
int n,m;
vvint adj;
vector <bool> vis;

void dfs(int s){
	vis[s] = 1;
	for(int u : adj[s]){
		if(!vis[u]) dfs(u);
	}
	return;
}

void solve(){
	cin >> n >> m;
	adj = vvint(n);
	vis = vector <bool> (n,0);
	for(int i = 0;i < m;++i){
		int x,y,z;
		cin >> x >> y >> z;
		--x,--y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	int ans = 0;
	for(int i = 0;i < n;++i){
		if(!vis[i]){
			dfs(i);
			++ans;
		}
	}
	cout << ans << newl;
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
