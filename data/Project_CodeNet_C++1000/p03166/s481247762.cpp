#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) ;
#define MOD 1000000007
#define int long long
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int,int>>
#define ff first
#define ss second
#define INF (1LL<<61)

using namespace std;

int n, m;
vi adj[500010];
int vis[500010];
int dp[500010];

void dfs(int sv) {

	vis[sv] = 1;
	for (auto ch : adj[sv]) {
		if (!vis[ch])
			dfs(ch);

		dp[sv] = max(dp[sv] , 1 + dp[ch]);

	}

}



int32_t main() {

	fastio
// #ifndef ONLINE_JUDGE
// freopen("input.txt", "r", stdin);
// freopen("output.txt","w", stdout);
// #endif

	cin >> n >> m;
	for (int i = 1 ; i <= m ; i++) {
		int x , y;
		cin >> x >> y;
		adj[x].pb(y);
	}

	for (int i = 1 ; i <= n ; i++)if (!vis[i])dfs(i);

	int ans = 0;
	for (int i = 1 ; i <= n ; i++)ans = max(ans , dp[i]);
	cout << ans << '\n';

	return 0;
}
