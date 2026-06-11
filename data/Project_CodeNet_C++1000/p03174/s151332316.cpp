#include <bits/stdc++.h>
#define ll long long


using namespace std;

const ll mod = 1e9 + 7;
	

int main()
{

	int n;
	cin >> n;

	int ALL_WOMEN = (1<<n);
	vector<ll> dp(ALL_WOMEN);
	int a[200][200];

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> a[i][j];
		}
	}


	//memset(dp, 0, sizeof(dp));

	dp[0] = 1;
	for (int mask = 0; mask < ALL_WOMEN - 1; mask++)
	{
		int i = __builtin_popcount(mask); //how many bits have

		for (int j = 0; j < n; j++)
		{
			if(a[i][j] == 1 && !(mask&(1<<j)))
			{
				int m2 = mask^(1<<j);
				dp[m2] = (dp[m2] + dp[mask]) % mod;
			}

		}

	}

	cout << dp[ALL_WOMEN-1] << endl;







    return 0;
}