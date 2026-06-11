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
	rep(i, len)
	{
		if (s == t)
			break;
		string tmp; tmp += s.back();
		s.insert(0, tmp);
		s.erase(len);
		// cout << s << endl;
	}
	if (s == t)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}