#include <bits/stdc++.h>
#define ll long long
#define M 1000000007 
#define MM 998244353
#define PI 3.14159265 
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	int h[n];
	
	for (int i = 0; i < n; i++)
	{
		cin >> h[i];
	}

	long long int dp[n]; 

	for (int i = 0; i<n ; i++)
	{
		dp[i] = M;
	}

	dp[0] = 0;

	dp[1] = abs(h[1] - h[0]);

	for (int i = 2; i < n; i++)
	{
		for (int j = k; j > 0; j--)
		{
			if (i - j >= 0)
			{
				dp[i] = min(dp[i], dp[i-j] + abs(h[i] - h[i-j]));
			}
		}
	}

	cout << dp[n-1];
	
  	return 0;
}