#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 310;
int n, a[4];
double dp[N][N][N];

double solve(int x, int y, int z)
{
	if (x < 0 || y < 0 || z < 0)
		return 0;
	if (x == 0 && y == 0 && z == 0)
		return 0;
	if (dp[x][y][z] != -1.0)
		return dp[x][y][z];
	double &ret = dp[x][y][z];
	double m = x + y + z;
	double val = n + x * solve(x - 1, y, z) + y * solve(x + 1, y - 1, z) + z * solve(x, y + 1, z - 1);
	return ret = val / m;
}

int main()
{
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int b;
		cin >> b;
		a[b]++;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			fill_n(dp[i][j], N, -1.0);
		}
	}
	double ans = solve(a[1], a[2], a[3]);
	cout << fixed << setprecision(12) << ans;

	return 0;
}