#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int INF = 1e9+5;

int dp[N];
bool vis[N];
vector<int> adj[N];
int mx=0;

int calc(int x) {
	
	if (x <1 ) return -1 *INF;
	if (vis[x]) return dp[x];
	
	vis[x] = 1;
	
	int mx_dist = 0;
	if (adj[x].size() ) 
		for (auto i : adj[x]) {
			mx_dist = max(mx_dist, calc(i) + 1);
		}
	
	return dp[x] = max(dp[x],mx_dist);
}
		
int main () {
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n,m;
	cin>>n>>m;
	
	for (int i=0;i<m;i++) {
		int x,y;
		cin>>x>>y;
		
		adj[x].push_back(y);
	}
	
	for (int i=1;i<=n;i++) {
		if (!vis[i]) calc(i);
		
		mx=max(mx,dp[i]);
	}
	
	cout<<mx<<'\n';
}
