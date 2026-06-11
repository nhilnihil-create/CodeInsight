#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int n, m;
	map<int, int> mp;
	bool ok;

	cin >> n;
	rep(i, n)
	{
		int a;
		cin >> a;
		mp[a]++;
	}
	cin >> m;
	ok = true;
	rep(i, m)
	{
		int b;
		cin >> b;
		if (mp.count(b) && mp[b] > 0)
			mp[b]--;	
		else
			ok = false;
	}
	if (ok)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
