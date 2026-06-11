#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	long long n, ans;
	cin >> n;
	ans = 0;
	for(int i = 1; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			if (n / i - i > 1)
				ans += n / i - 1;
		}
	}
	cout << ans << endl;
	return 0;
}
