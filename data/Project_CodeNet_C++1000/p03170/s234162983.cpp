#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long i, j, dp[100001] = {0}, a[101], n, k;
	cin >> n >> k;
	for(i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	dp[0] = 0;
	for(i = 1; i <= k; i++)
	{
		for(j = 0; j < n; j++)
		{
			if(i - a[j] >= 0)
			{
				dp[i] |= !dp[i - a[j]];
			}
		}
	}
	if(dp[k])
		cout << "First";
	else
		cout << "Second";
	return 0;
}