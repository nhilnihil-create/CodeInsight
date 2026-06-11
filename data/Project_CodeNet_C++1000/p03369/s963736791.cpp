#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int ans;
	ans = 700;
	rep(i, 3)
	{
		char c;
		cin >> c;
		if (c =='o') ans += 100;
	}
	cout << ans << endl;
	return 0;
}
