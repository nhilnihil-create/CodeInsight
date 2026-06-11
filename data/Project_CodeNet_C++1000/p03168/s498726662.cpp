#include<iostream>
#include<cstring>
#include<iomanip>
#define int long long
using namespace std;
double dp[3001][3001];
double func(double a[], int i, int x)
{
	if (x == 0)
	{
		return 1;
	}
	if (i == 0)
	{
		return 0;
	}
	if (dp[i][x] > -0.9)
	{
		return dp[i][x];
	}
	return dp[i][x] = a[i] * func(a, i - 1, x - 1) + (1 - a[i]) * (func(a, i - 1, x));
}
int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	double a[n + 1];
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	memset(dp, -1, sizeof(dp));
	double ans = func(a, n, (n + 1) / 2);
	cout << fixed << setprecision(12) << ans << "\n";
}