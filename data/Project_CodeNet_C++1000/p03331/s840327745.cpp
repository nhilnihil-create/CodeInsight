#include <bits/stdc++.h>
#define rep(i, n) for(int i = 1; i <= (n) / 2; i++)
using namespace std;

signed main(void)
{
	int n;
	int ans, sum;
	cin >> n;
	ans = 1e9;
	rep(i, n)
	{
		int x, y;
		x = i;
		y = n - i;	
		sum = 0;
		while(x)
		{
			sum += x % 10;
			x /= 10;
		}
		while(y)
		{
			sum += y % 10;
			y /= 10;
		}
		ans = min(ans, sum);
	}
	cout << ans << endl;
	return 0;
}
