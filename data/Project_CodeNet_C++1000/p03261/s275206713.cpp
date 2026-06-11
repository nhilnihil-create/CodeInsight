#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
using P = pair<int,int>;
typedef long long ll;

int  main()
{
	int n; cin >> n;
	string s[n];
	rep(i, n)
		cin >> s[i];
	set<string> st;
	char e = s[0].back();
	st.insert(s[0]);
	rep1(i, n)
	{
		if (e != s[i].front())
		{
			cout << "No"; return 0;
		}
		if (st.count(s[i]))
		{
			cout << "No"; return 0;
		}
		e = s[i].back();
		st.insert(s[i]);
	}
	cout << "Yes\n";
	return (0);
}
