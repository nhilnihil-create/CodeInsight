#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef long long ll;
typedef long double ld;

int check(string s, string t)
{
	rep(i, t.size())
	{
		if (s[i] == '?')
			s[i] = t[i];
	}
	if (t == s)
		return 1;
	return 0;
}

int  main()
{
	string s; cin >> s;
	string t; cin >> t;
	int t_len = t.size();
	bool ans = false;
	// rep(i, (s.size() - t_len) + 1)
	// {
	// 	string ss = s.substr(i, t_len);
	// 	if (check(ss, t))
	// 	{
	// 		s.replace(i, t_len, t);
	// 		ans = true;
	// 	}
	// }
	for (int i = s.size()-1; i >= (t_len-1); i--)
	{
		string ss = s.substr(i - (t_len-1), t_len);
		if (check(ss, t))
		{
			s.replace(i - (t_len - 1), t_len, t);
			ans = true;
			break;
		}
	}
	if (ans)
	{
		rep(i, s.size())
		{
			if (s[i] == '?')
				s[i] = 'a';
		}
		cout << s << endl;
	}
	else
		cout << "UNRESTORABLE" << endl;
	return 0;
}
