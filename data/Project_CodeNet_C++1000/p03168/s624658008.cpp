#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 3001;
double dp[N + 1][N + 1];
double a[N];

double solve(int i, int x) {
	if (x == 0)
		return 1;
	if (i == -1)
		return 0;
	if (dp[i][x] > -0.9)
		return dp[i][x];
	return dp[i][x] = (solve(i - 1, x - 1) * a[i] + solve(i - 1, x) * (1 - a[i]));
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	memset(dp, -1, sizeof(dp));
	cout << fixed << setprecision(10) << solve(n, (n + 1) / 2);

	return 0;
}