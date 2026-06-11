#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
using P = pair<int, int>;
#define MAX 100010

vector<int> dp(MAX);
signed main(void)
{
	int n;
	cin >> n;
	rep(x, MAX)
	{
		dp[x] = x;
		int p = 6;
		while (p < MAX)
		{
			if (x - p >= 0)
				dp[x] = min(dp[x], dp[x - p] + 1);
			p *= 6;
		}
		p = 9;
		while (p < MAX)
		{
			if (x - p >= 0)
				dp[x] = min(dp[x], dp[x - p] + 1);
			p *= 9;
		}
	}
	cout << dp[n] << endl;
	return 0;
}
