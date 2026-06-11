#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int n, m, d;
	long long sum;
	double ans;

	cin >> n >> m >> d;
	if (d != 0)
	{
		sum = 2 * (n - d);
		ans = (double) sum / n;
		ans /= n;
	}
	else
		ans = (double) 1 / n;
	ans *= m - 1;
	cout << fixed << setprecision(20) << ans << endl;
	return 0;
}
