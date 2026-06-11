#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

signed main(void)
{
	string s;
	cin >> s;
	rep(i, 3)
	{
		if (s[i] == '9')
			s[i] = '1';
		else if (s[i] == '1')
			s[i] = '9';
	}
	cout << s << endl;
	return 0;
}
