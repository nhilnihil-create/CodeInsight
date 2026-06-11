#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;

signed main(void)
{
	int n, ans;
	cin >> n;

	ans = 0;
	rep(i, n)
	{
		if (i * i > n)
			break;
		ans = i;
	}
	cout << ans * ans << endl;
	return 0;
}
