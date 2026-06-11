#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin >> s;
	bool ok = 1;
	for (int i = 1; i < s.size(); ++i)
	{
		ok *= (s[i] == '9');
	}
	if (ok)
	{
		cout << 9 * (s.size() - 1) + (max(0,(int)(s[0] - '0'))) << endl;
	}
	else
	{
		cout << 9 * (s.size() - 1) + (max(0,(int)(s[0] - '0')-1)) << endl;
	}
	return 0;
}