#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed  main(void)
{
	string s;
	set<char> st;
	
	cin >> s;
	rep(i, s.size())
		st.insert(s[i]);
	if (st.size() != 26)
	{
		for(char c = 'a'; c <= 'z'; c++)
		{
			if (!st.count(c)) 
			{
				s += c;
				break;
			}
		}
		cout << s << endl;
	}
	else
	{
		if (s == "zyxwvutsrqponmlkjihgfedcba")
			cout << -1 << endl;
		else
		{
			string t = s;
			next_permutation(t.begin(), t.end());
			rep(i, 26)
			{
				if (t[i] != s[i])
				{
					cout << t.substr(0, i + 1) << endl;
					break;
				}
			}
		}
	}
	return 0;
}
