#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
const ll MOD = 1e9 + 7;
int n;
ll dp[N][2];
vector<int> v[N];

ll solve(int src, int prev, int color) {
	if (dp[src][color] != -1) {
		return dp[src][color];
	}
	ll ways = 1, ans = 0;
	if (color == 0) {
		for (auto it : v[src]) {
			if (it != prev) {
				ways = (ways * solve(it, src, 1)) % MOD;
			}
		}
		ans = (ans + ways) % MOD;
	}
	ways = 1;
	for (auto it : v[src]) {
		if (it != prev) {
			ways = (ways * solve(it, src, 0)) % MOD;
		}
	}
	ans = (ans + ways) % MOD;
	return dp[src][color] = ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	int x, y;
	for (int i = 1; i <= n - 1; i++) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	memset(dp, -1, sizeof(dp));
	ll answer = solve(1, 0, 0);
	cout << answer;

	return 0;
}
