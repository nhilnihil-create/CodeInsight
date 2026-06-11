#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define pb push_back
#define endl '\n'
#define snd second
#define fst first
#define fastio cin.tie(NULL),cout.sync_with_stdio(true)

typedef long long int ll;
typedef unsigned long long int ull;
typedef vector <int> vi;
typedef pair <ll,int> ii;
typedef pair <ii,int> iii;

const int mod = 1e9 + 7;
const ll INF = (1LL<<50);
const int N = 100005;

vi adj[N];
int dp[N];

int dfs(int x){
	if(dp[x] != -1)
		return dp[x];
	if(adj[x].empty())
		return 0;
	int ans = 0;
	for(auto i:adj[x])
		ans = max(ans, 1 + dfs(i));
	return dp[x] = ans;
}

int main(){
	fastio;
	memset(dp, -1, sizeof(dp));
	int n,m;
	cin >> n >> m;
	while(m--){
		int x, y;
		cin >> x >> y;
		adj[x].pb(y);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(dp[i] == -1)
			ans = max(ans, dfs(i));
	}
	cout << ans << endl;
	return 0;
}
