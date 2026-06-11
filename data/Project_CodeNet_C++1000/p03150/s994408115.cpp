#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	string s, tmp;
	bool ok;

	cin >> s;
	ok = false;
	rep(i, s.size())
	{
		for(int j = 0; i + j <= s.size(); j++)
		{
			tmp = "";
			tmp += s.substr(0, i); 
			tmp += s.substr(i + j, s.size() - j);
			if (tmp == "keyence")
				ok = true;
		}
	}
	if (ok)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
