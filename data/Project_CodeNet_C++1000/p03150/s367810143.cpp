#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int  main()
{
	string s; cin >> s;
	string key = "keyence";
	int j = 0;
	string ans;
	rep(i, s.size())
	{
		if(s[i] == key[j])
		{
			ans.push_back(s[i]);
			j++;
		}
		else
		{
			int r = s.size() - (key.size() - ans.size());
			ans += s.substr(r, (key.size() - ans.size()));
			break;
		}
	}
	if (ans == key)
		cout << "YES\n";
	else
		cout << "NO\n";
	return (0);
}
