#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 1e5 + 7, M = 1e9 + 7;

vi G[N];
int dp[N][2];

void dfs(int u, int p = -1) {
	dp[u][0] = dp[u][1] = 1;
	for(int v:G[u]) if(v != p){
		dfs(v, u);
		dp[u][0] = (ll) dp[u][0] * (dp[v][0] + dp[v][1]) % M;
		dp[u][1] = (ll) dp[u][1] * dp[v][0] % M;
	}
}

signed main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		G[u].PB(v);
		G[v].PB(u);		
	}
	dfs(1);
	cout << (dp[1][0] + dp[1][1]) % M << endl;


}

