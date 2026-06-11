#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, a[4];
vector<vector<vector<double>>> dp;

double solve(int x, int y, int z) {
	if (x < 0 || y < 0 || z < 0) {
		return 0;
	}
	if (x == 0 && y == 0 && z == 0) {
		return 0;
	}
	if (dp[x][y][z] != -1.0) {
		return dp[x][y][z];
	}
	int rem = x + y + z;
	double value = n + x * solve(x - 1, y, z) + y * solve(x + 1, y - 1, z) + z * solve(x, y + 1, z - 1);
	return dp[x][y][z] = value / rem;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	dp.resize(n + 1);
	for (int i = 0; i <= n; i++) {
		dp[i].resize(n + 1);
		for (int j = 0; j <= n; j++) {
			dp[i][j].resize(n + 1, -1.0);
		}
	}
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a[x]++;
	}
	double answer = solve(a[1], a[2], a[3]);
	cout << fixed << setprecision(12) << answer;

	return 0;
}