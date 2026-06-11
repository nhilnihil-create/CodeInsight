#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	string s, t;
	int tmp;

	cin >> s;
	rep(i, s.size() - 7)
	{
		if (s.substr(i, 8) == "FESTIVAL")
			tmp = i;	
	}
	rep(i, tmp) cout << s[i];
	cout << endl;
	return 0;
}
