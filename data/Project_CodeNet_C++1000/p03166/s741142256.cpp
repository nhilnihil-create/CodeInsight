/// @pSaurabh

#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define print(a, n) for(int i = 0; i < n; i++) if(i < n - 1){ cout << a[i] << " "; } else cout << a[i] << "\n";

typedef long long ll;
typedef long double ld;

const ll mod = 1e9 + 7;

void fast(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout .tie(0);
}

int ans = 0;
map <int, vector <int>> adj;
vector <int> dp(100001, -1);

void dfs(int cur){
	if(dp[cur] != -1){
		return;
	} 
	if(!adj.count(cur)){
		dp[cur] = 0;
		return;
	}

	int mx = 0;

	for(auto it: adj[cur]){
		dfs(it);
		mx = max(mx, dp[it]);
	}

	dp[cur] = 1 + mx;
	ans = max(ans, dp[cur]);
}

int main(){
	// fast();

	int n, m;
	cin >> n >> m;

	int x, y;
	for(int i = 0; i < m; ++i){
		cin >> x >> y;
		--x; --y;
		adj[x].push_back(y);
	}

	for(int i = 0; i < n; ++i){
		dfs(i);
	}

	cout << ans << "\n";

	return 0;
}
