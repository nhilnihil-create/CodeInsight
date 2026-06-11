#include <bits/stdc++.h>
using namespace std;

signed main(void)
{
	long long x, y;
	long long ans;
	cin >> x >> y;

	ans = 0;
	for(long long i = x; i <= y; i *= 2)
		ans++;
	cout << ans << endl;
}
