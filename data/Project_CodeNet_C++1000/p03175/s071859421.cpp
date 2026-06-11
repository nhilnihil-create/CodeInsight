#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back

typedef long long ll;

const ll MOD = 1e9+7;
const ll INF = 1e9+5;

vector <int> v[100005];

int memo[100005][2];

int dp(int node, int par, int c) {
	if (memo[node][c] != -1) return memo[node][c];
	ll sol = 1;
	ll dod = 0;
	for (int i=0 ; i<v[node].size() ; i++) {
		int nx = v[node][i];
		if (nx == par) continue;
		sol = (sol * dp(nx, node, 0)) % MOD;
	}
	if (c == 0) {
		dod = 1;
		for (int i=0 ; i<v[node].size() ; i++) {
			int nx = v[node][i];
			if (nx == par) continue;
			dod = (dod * dp(nx, node, 1)) % MOD;
		}
	}
	return memo[node][c] = (sol + dod) % MOD;
}

int main() {
	memset(memo, -1, sizeof memo);
	int n;
	scanf("%d", &n);
	for (int i=0 ; i<n-1 ; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].pb(y);
		v[y].pb(x);
	}
	printf("%d\n", dp(1, 0, 0));
	return 0;
}