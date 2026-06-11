#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX
#define int long long
#define mod 1000000007

double dp[301][301][301];

double solve1(int x, int y, int z, int n) {
	if (x < 0 || y < 0 || z < 0)return 0;
	if (dp[x][y][z] >= 0)return dp[x][y][z];
	double val = n + x * solve1(x - 1, y, z, n) + y * solve1(x + 1, y - 1, z, n) + z * solve1(x, y + 1, z - 1, n);
	return dp[x][y][z] = val / (x + y + z);
}


void solve() {
	int n;
	cin >> n;
	int one = 0, two = 0, three = 0;
	int i;
	for (i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x == 1)one++;
		else if (x == 2)two++;
		else three++;
	}
	memset(dp, -1, sizeof(dp));
	dp[0][0][0] = 0;
	double len = solve1(one, two, three, n);
	cout << fixed << setprecision(10) << len << endl;
	return;
}


int32_t main() {
	std::ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	solve();
	return 0;
}