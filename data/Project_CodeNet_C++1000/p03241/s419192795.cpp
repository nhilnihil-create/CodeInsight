#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int n, m, ans;

	cin >> n >> m;
	ans = 0;
	for(int i = 1; i <= sqrt(m); i++)
	{
		if (m % i == 0)
		{
			if (m / n >= i)
				ans = max(ans, i);
			if (m / n >= m / i)
				ans = max(ans, (int)m / i);
		}
	}
	cout << ans << endl;
	return 0;
}
