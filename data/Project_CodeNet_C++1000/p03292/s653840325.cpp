#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	vector<int> v(3);
	int ans;
	rep(i, 3) cin >> v.at(i);
	sort(v.begin(), v.end());
	ans = 0;
	for(int i = 1; i < 3; i++)
	{
		ans += v.at(i) - v.at(i - 1);
	}
	cout << ans << endl;
	return 0;
}
