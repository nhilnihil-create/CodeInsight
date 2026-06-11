#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	long long k, a, b, ans;

	cin >> k >> a >> b;
	k++;
	if (b - a <= 2)
		ans = k;
	else
	{
		ans = a;
		ans += (k - a) / 2 * (b - a) + (k - a) % 2;
	}
	cout << ans << endl;
	return 0;
}
