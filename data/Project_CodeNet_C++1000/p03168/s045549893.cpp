#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<double>p;
ll n;
vector<vector<double>>dp;

double F(int idx, int diff)
{
	if (idx == n)
		return diff > 0;
	if (dp[idx][diff + n] != -1)
		return dp[idx][diff + n];
	double a = F(idx + 1, diff + 1) * p[idx];
	double b = F(idx + 1, diff - 1) * (1 - p[idx]);
	return (dp[idx][diff + n] = a + b);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n; p = vector<double>(n);
	for (auto &it : p)
		cin >> it;
	dp = vector<vector<double>>(n, vector<double>(2 * n + 1, -1));
	cout << fixed << setprecision(11) << F(0, 0);

	return 0;
}