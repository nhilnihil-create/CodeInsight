#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int n;
	cin >> n;
	int a[n];
	long long ans, cnt;
	ans = pow(3, n);
	cnt = 1;
	rep(i, n)
	{
		cin >> a[i];
		if (a[i] % 2 == 0)
			cnt *= 2;	
	}
	ans -= cnt;
	cout << ans << endl;
	return 0;
}
