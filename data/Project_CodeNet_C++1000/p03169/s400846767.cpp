#include<bits/stdc++.h>
using namespace std;

#define ll long long

int n, x, cnt[4];
double dp[303][303][303];
// x - no of plates with 1 sushi
// y - no of plates with 2 sushi
// z - no of plates with 3 sushi

double solve (int x, int y, int z) {
	if (x < 0 || y < 0 || z < 0) {
		return 0;
	}

	if (x == 0 && y == 0 && z == 0) {
		return 0;
	}

	if (dp[x][y][z] > -0.9) {
		return dp[x][y][z];
	}

	//dp[x][y][z] = 1 + p0*dp[x][y][z] + px*dp[x-1][y][z] + py * dp[x+1][y-1][z] + pz * dp[x][y+1][z-1];
	//p0 = probability of selecting plate with 0 sushi = n - (x + y + z)/  n;
	//p1 = probability of selecting plate with 1 sushi = x/n;
	//p2 = probability of selecting plate with 2 sushi = y/n;
	//p3 = probability of selecting plate with 3 sushi = z/n;

	return dp[x][y][z] = (n + x * solve(x - 1, y, z) + y * solve (x + 1, y - 1, z) + z * solve (x, y + 1, z - 1)) / (x + y + z);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	cnt[1] = cnt[2] = cnt[3] = 0;

	for (int i = 0; i < n; i++) {
		cin >> x;
		cnt[x]++;
	}

	memset(dp, -1, sizeof dp);
	double ans = solve (cnt[1], cnt[2], cnt[3]);
	cout << fixed << setprecision(10) << ans;
	return 0;
}