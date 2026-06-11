#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	string s;
	int a[4];

	a[0] = 0;
	a[1] = 4;
	a[2] = 6;
	a[3] = 8;
	cin >> s;
	rep(i, 4) 
	{
		if (s.size() >= a[i])
		{
			if (s[a[i]] == 'A')
				continue;
			else
				s.insert(s.begin() + a[i], 'A');
		}
	}
	if (s == "AKIHABARA")
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
