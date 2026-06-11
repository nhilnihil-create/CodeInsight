#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

signed main(void)
{
	int n;
	string a, b, c;
	cin >> n >> a >> b >> c;
	long long ans = 0;
	rep(i, n)
	{
		map<char, int> mp;
		mp[a[i]]++;
		mp[b[i]]++;
		mp[c[i]]++;
		ans +=  mp.size() - 1;
	}
	cout << ans << endl;
	return 0;
}
