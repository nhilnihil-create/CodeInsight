#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int a, b, c;
	int ans;
	cin >> a >> b >> c;
	ans = b;
	if (c - b <= 0)
		ans += c;
	else
	{
		c -= b;
		ans += b;
		c--;
		ans++;
		if (c <= a)
			ans += c;
		else
			ans += a;
	}
	cout << ans << endl;
	return 0;
}
