#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int n;
	double ans;

	cin >> n;
	ans = 0;
	rep(i, n)
	{
		double x;
		string u;
		cin >> x >> u;
		if (u == "JPY")
			ans += x;
		else if (u == "BTC")
			ans += x * 380000.0;
	}
	cout << fixed << setprecision(4) << ans << endl;
	return 0;
}
