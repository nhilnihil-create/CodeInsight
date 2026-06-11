#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	string s, t;
	cin >> s >> t;
	if (s[0] == t[2] && s[1] == t[1] && s[2] == t[0])
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
