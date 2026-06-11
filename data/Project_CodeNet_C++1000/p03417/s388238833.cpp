#include <bits/stdc++.h>
using namespace std;

signed main(void)
{
	long long n, m;
	long long ans;

	cin >> n >> m;
	ans = 0;
	if (n >= 2 && m >= 2)
		ans = (n - 2) * (m - 2);
	else if (n == 1 && m >= 2)
		ans = m - 2;
	else if (m == 1 && n >= 2)
		ans = n - 2;
	else if (n == 1 && m == 1)
		ans = 1;
	cout << ans << endl;
	return 0;
}
