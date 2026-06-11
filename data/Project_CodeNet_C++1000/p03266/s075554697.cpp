#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int n, k;
	long long cnt1, cnt2, ans;

	cin >> n >> k;
	cnt1 = cnt2 = ans = 0;
	for(int i = 1; i <= n; i++)
	{
		if (i % k == 0)
			cnt1++;
		if (k % 2 == 0 && i % k == k / 2)
			cnt2++;
	}
	ans = cnt1 * cnt1 * cnt1 + cnt2 * cnt2 * cnt2;
	cout << ans << endl;
	return 0;
}
