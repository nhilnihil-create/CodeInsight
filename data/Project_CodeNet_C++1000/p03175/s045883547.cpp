#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod 			1000000007
#define tc(t) 			int t;cin >> t;while(t--)
#define for0(i , n)		for(int i=0;i<n;i++)
#define loop(i , a, b)	for(int i=a;i<=b;i++)
#define endl 			'\n'
#define inf 			1e18
#define fi 				first
#define se 				second

int XX[8] = { +1, +1, +1, 0, 0, -1, -1, -1};
int YY[8] = { +1, 0, -1, +1, -1, +1, 0, -1};
int dx[4] = { -1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

vector<int> adj[100005];
int dp[100005][2];
int n;

int dfs(int node, int col, int par) {
	if (dp[node][col] != -1) return dp[node][col];
	int ans = 0, w1 = 1;
	for (auto it : adj[node]) {
		if (it != par) {
			w1 = (w1 * dfs(it, 0, node)) % mod;
		}
	}

	ans += w1;
	if (ans >= mod) ans -= mod;
	if (!col) {
		int w2 = 1;
		for (auto it : adj[node]) {
			if (it != par) {
				w2 = (w2 * dfs(it, 1, node)) % mod;
			}
		}
		ans += w2;
		if (ans >= mod)ans -= mod;
	}

	return dp[node][col] = ans;
}

signed main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
#endif

	cin >> n;

	for (int i = 1; i <= n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	memset(dp, -1, sizeof(dp));

	cout << dfs(1, 0, -1) << endl;

	return 0;
}