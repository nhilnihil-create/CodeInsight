#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 1e9+7;

int main(){ _

	int n; cin >> n;
	vector<vector<int>> g(n);
	for(int i=0; i<n-1; i++) {
		int a, b; cin >> a >> b; a--, b--;

		g[a].push_back(b);
		g[b].push_back(a);
	}

	vector<vector<ll>> memo(2,vector<ll>(n,-1)); // 0 am black, 1 am white

	function<void(int)> dfs = [&] (int x) {
		memo[0][x] = memo[1][x] = 1;

		for(auto u : g[x]) if(memo[0][u] == -1) {
			dfs(u);
			memo[0][x] = memo[0][x] * memo[1][u] % MOD;
			memo[1][x] = memo[1][x] * ((memo[0][u] + memo[1][u]) % MOD) % MOD;
		}
	};

	dfs(0);

	cout << (memo[0][0] + memo[1][0]) % MOD << endl;

	return 0;
}
