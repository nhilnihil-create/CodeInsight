#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

signed main(void)
{
	string s;
	int k, cnt;
	set<string> st;

	cin >> s >> k;
	for(int j = 1; j <= k; j++)
	{
		rep(i, s.size())
		{
			string t = s.substr(i, j);
			st.insert(t);
		}
	}
	cnt = 0;
	for(auto v : st)
	{
		cnt++;
		if (cnt == k)
		{
			cout << v << endl; 
			break;
		}
	}
	return 0;
}
