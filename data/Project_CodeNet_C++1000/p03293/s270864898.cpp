#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef long long ll;
typedef long double ld;

int  main()
{
	string s; cin >> s;
	string t; cin >> t;
	int len = s.size();
	
	for (int i = 0; i < len; i++)
	{
		string ans;
		for (int j = i; i < len; j++)
		{
			ans += s[j];
			if (j == len - 1 && ans.size() < len)
				j = -1;
			if (ans.size() == len)
				break;
		}
		if (ans == t)
		{
			cout << "Yes" << endl; return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}
