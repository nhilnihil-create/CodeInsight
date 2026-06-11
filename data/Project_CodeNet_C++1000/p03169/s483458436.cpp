#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int ones = 0, twos = 0, threes = 0;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];

		if (arr[i] == 1)ones++;
		else if (arr[i] == 2)twos++;
		else threes++;
	}
	int mones = ones + twos + threes;
	int mtwos = twos + threes;
	int mthrees = threes;
	double dp[n + 1][n + 1][n + 1];
	memset(dp, 0, sizeof(dp));
	int i, j, k;
	for (k = 0; k <= mthrees; k++)
	{
		for (j = 0; j <= mtwos - k; j++)
		{
			for (i = 0; i <= mones - j - k; i++)
			{
				if (i + j + k == 0)continue;
				else
				{
					dp[i][j][k] = (double)n / (i + j + k);
					if (i > 0)
						dp[i][j][k] += (double)(dp[i - 1][j][k] * i) / (i + j + k);
					if (j > 0)
						dp[i][j][k] += (double)(dp[i + 1][j - 1][k] * j) / (i + j + k);
					if (k > 0)
						dp[i][j][k] += (double)(dp[i][j + 1][k - 1] * k) / (i + j + k);
				}
			}
		}
	}
	cout << fixed << setprecision(9) << dp[i-1][j-1][k-1];
	return 0;
}