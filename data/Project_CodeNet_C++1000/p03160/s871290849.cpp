#include<iostream>
#include<cstring>
#include<vector>
#define int long long
using namespace std;
int ans = 0;
int func(vector<int>a, int n)
{
	vector<int>dp(n + 1, 0);
	dp[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		int option1 = abs(a[i] - a[i - 1]) + dp[i - 1];
		int option2 = (i == 2) ? 1e9 : abs(a[i] - a[i - 2]) + dp[i - 2];
		dp[i] = min(option1, option2);
	}
	return dp[n];
}
int32_t main()
{
	int n;
	cin >> n;
	vector<int>a(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	cout << func(a, n ) << "\n";
}