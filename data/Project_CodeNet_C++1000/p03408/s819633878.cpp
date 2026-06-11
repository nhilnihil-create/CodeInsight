#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<string> ss(n);
	for (auto &&s : ss)
	{
		cin >> s;
	}
	int m;
	cin >> m;
	vector<string> ts(m);
	for (auto &&t : ts)
	{
		cin >> t;
	}

	set<string> st;
	for (auto &&s : ss)
	{
		st.insert(s);
	}
	for (auto &&t : ts)
	{
		st.insert(t);
	}

	map<string, int> g, l;
	for (auto &&s : ss)
	{
		g[s]++;
	}
	for (auto &&t : ts)
	{
		l[t]++;
	}

	int ans = 0;

	for (auto &&u : st)
	{
		ans = max(ans, g[u] - l[u]);
	}

	cout << ans << endl;

	return 0;
}