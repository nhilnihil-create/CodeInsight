#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 22;
const ll mod = 1e9 + 7;
ll dp[N][1 << N];
int n;
bool a[N][N];

ll solve(int m, int w) {
	if (m == n) {
		if (w == 0)
			return 1;
		return 0;
	}
	if (dp[m][w] != -1)
		return dp[m][w];
	ll tot = 0;
	for (int i = 0; i < n; i++) {
		int woman = 1 << i;
		bool available = ((woman & w) == 0)? false : true;
		if (available && a[m][i]) {
			tot = (tot + solve(m + 1, woman ^ w)) % mod;
		}
	}
	return dp[m][w] = tot;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	int x;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> x;
			if (x)
				a[i][j] = true;
		}
	}
	memset(dp, -1, sizeof(dp));
	ll answer = solve(0, ((1 << n) - 1));
	cout << answer;

	return 0;
}
