#include<bits/stdc++.h>
using namespace std;
#define ll long long

double dp[3001][3001];

double solve(std::vector<double>& ar, int i, int x)
{
	//base case
	if (x == 0)
		return 1;
	if (i == 0)
		return 0;
	if (dp[i][x] > -0.9)//double should be avoided while comparing with -1
		return dp[i][x];
	return dp[i][x] = ar[i] * solve(ar, i - 1, x - 1) + (1 - ar[i]) * solve(ar, i - 1, x);
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	memset(dp, -1, sizeof dp);
	std::vector<double> ar(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> ar[i];
	cout << fixed << setprecision(19) << solve(ar, n, ((n + 1) / 2));
}