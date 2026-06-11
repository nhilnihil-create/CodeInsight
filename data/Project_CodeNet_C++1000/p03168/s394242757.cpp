#include<bits/stdc++.h>
using namespace std;
#define ll  long long int
const int  M = 1e9 + 7;

vector<vector<double>> dp;

double f(int n, int heads, vector<double> &v)
{

	if(n == 0)
	{
		if(2*heads > v.size())
			return 1;
		else
			return 0;
	}

	if(dp[n][heads] != -1)
		return dp[n][heads];
	double t1 = (dp[n-1][heads + 1] == -1) ? f(n-1, heads + 1, v) : dp[n-1][heads+1];
	double t2 = (dp[n-1][heads] == -1) ? f(n-1, heads, v) : dp[n-1][heads];
	
	return dp[n][heads] = v[n-1] * t1  + (1-v[n-1])*t2;
}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, i, j, wt, m;
	
	cin >> n;
	vector<double> v(n);
	for(i = 0; i < n; i++)
		cin >> v[i];

	dp.resize(n + 1);
	for(i = 0; i <= n; i++)
		dp[i].resize(n + 1, -1);

	cout << setprecision(10) << f(n, 0, v);
}
