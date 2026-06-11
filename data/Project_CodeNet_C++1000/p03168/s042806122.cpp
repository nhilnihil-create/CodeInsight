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
	double t1 = (dp[n-1][heads + 1] == -1) ? f(n-1, heads + 1, v) : dp[n-1][heads + 1];
	double t2 = (dp[n-1][heads] == -1) ? f(n-1, heads, v) : dp[n-1][heads];
	//cout << n << " " << heads << " " << v[n] << endl;
	//return v[n] * f(n-1, heads + 1, v)  + (1-v[n])*f(n-1, heads, v);
	return v[n-1] * t1  + (1-v[n-1])*t2;
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
		dp[i].resize(n + 1, 0);

	dp[0][0] = 1.0;

	//cout << setprecision(10) << f(n, 0, v);

	for(i = 1; i <= n; i++)             // i is for every coin...
	{
		for(j = 0; j <= i; j++)         // j is the number of heads
		{
			if(j == 0)
				dp[i][j] = dp[i-1][j] * (1.0 - v[i-1]);
			else
				dp[i][j] = dp[i-1][j-1] * v[i-1] + dp[i-1][j] * (1.0-v[i-1]);
		}

	}
	double sum = 0.0;
	for(i = (n+1)/2; i <= n; i++)
		sum += dp[n][i];
	cout << setprecision(10) << sum;
}
