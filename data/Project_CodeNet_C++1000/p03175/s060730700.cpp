#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 1e9 + 7, mxN = 1e5 + 5, mxC = 2;
int N;
vector<int> adj[mxN];
ll dp[mxN][mxC];

ll rec(int v, int p, int pcol) {
	if (dp[v][pcol] != -1)
		return dp[v][pcol];
	ll tot = 0, ways = 1;
	if (pcol == 0) {
		for (auto it : adj[v]) {
			if (it != p) {
				ways = (ways * rec(it, v, 1)) % mod;
			}
		}
		tot = ways;
	}
	ways = 1;
	for (auto it : adj[v]) {
		if (it != p) {
			ways = (ways * rec(it, v, 0)) % mod;
		}
	}
	tot = (tot + ways) % mod;
	return dp[v][pcol] = tot;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(dp, -1, sizeof(dp));
	ll answer = rec(1, 0, 0);
	cout << answer;

	return 0;
}