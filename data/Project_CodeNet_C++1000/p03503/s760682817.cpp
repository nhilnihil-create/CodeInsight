#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
const int mod = 1e9+7, A = 1e3+5;

int main()
{
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	bool a[n][10];
	int cost[n][11];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 10; j++)
			cin >> a[i][j];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 11; j++)
			cin >> cost[i][j];
	}
	ll ans = -2e18;
	for (int mask = 1; mask < (1 << 10); mask++)
	{
		ll val = 0;
		for (int i = 0; i < n; i++)
		{
			int ind = 0;
			for (int j = 0; j  < 10; j++)
			{
				if ((mask >> j & 1) && a[i][j])
					ind++;
			}
			val += cost[i][ind];
		}
		ans = max(ans, val);
	}
	cout << ans;
	return 0;
}