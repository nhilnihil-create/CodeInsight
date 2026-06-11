#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int n;
	string s;
	map<char, int> mp;
	cin >> n >> s;
	rep(i, n)
	{
		mp[s[i]]++;
	}
	if (mp['R'] > mp['B'])
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}
