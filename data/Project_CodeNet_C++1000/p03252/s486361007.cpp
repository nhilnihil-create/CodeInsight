#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	string s, t;
	cin >> s >> t;
	map<char, char> S, T;
	for (int i = 0; i < s.size(); ++i)
	{
		if (S.count(s[i]) == 0)
		{
			S[s[i]] = t[i];
		}
		if (T.count(t[i]) == 0)
		{
			T[t[i]] = s[i];
		}
		if(S[s[i]] != t[i] || T[t[i]] != s[i])
		{
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}