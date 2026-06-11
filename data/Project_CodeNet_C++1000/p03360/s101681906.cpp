#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

signed main(void)
{
	vector<int> a(3);
	int sum, k;
	cin >> a[0] >> a[1] >> a[2] >> k;
	rep(i, k)
	{
		sort(a.rbegin(), a.rend());
		a[0] *= 2;
	}
	sum = 0;
	rep(i, 3) sum += a[i];
	cout << sum << endl;
	return 0;
}
