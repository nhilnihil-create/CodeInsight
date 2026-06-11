#include <bits/stdc++.h>

using namespace std;

int n, sum;
bitset<4000010> dp;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	dp.set(0);
	for (int i = 1; i <= n; i++)
	{
		int x; cin >> x;
		sum += x;
		dp |= (dp << x);
	}
	for (int i = (sum + 1) / 2; ; i++)
		if (dp[i])
		{
			cout << i << endl;
			break;
		}
	return 0;
}
