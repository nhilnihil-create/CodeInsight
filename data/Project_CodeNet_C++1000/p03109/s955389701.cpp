#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	string s;
	cin >> s;
	bool ok = false;
	if (s.substr(0, 4) < "2019")
		ok = true;
	else if (s.substr(0, 4) == "2019")
	{
		if (s.substr(5, 2) < "04")
			ok = true;
		else if (s.substr(5, 2) == "04")
			if (s.substr(8, 2) <= "30")
				ok = true;
	}
	if (ok)
		cout << "Heisei" << endl;
	else
		cout << "TBD" << endl;
	return 0;
}
