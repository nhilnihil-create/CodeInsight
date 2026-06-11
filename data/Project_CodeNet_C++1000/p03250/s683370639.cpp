#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

signed main(void)
{
	vector<int> a(3);
	cin >> a[0] >> a[1] >> a[2];
	sort(a.rbegin(), a.rend());
	cout << 10 * a[0] + a[1] + a[2] << endl;
	return 0;
}
