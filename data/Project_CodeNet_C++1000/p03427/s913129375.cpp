#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	string s;
	int ans;
	bool ok;

	cin >> s;
	ok = true;
	ans = 9 * (s.size() - 1) + (s[0] - '0');
	for(int i = 1; i < s.size(); i++)
	{
		if (s[i] != '9')
			ok = false;
	}
	if (!ok && s.size() != 1) ans--;
	cout << ans << endl;
	return 0;
}
