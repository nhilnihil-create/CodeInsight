#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n; cin >> n;
	map<string, int> dict;
	for (int i = 0; i < n; ++i)
	{
		string s; cin >> s;
		dict[s]++;
	}
	int m; cin >> m;
	for (int i = 0; i < m; ++i)
	{
		string t; cin >> t;
		dict[t]--;
	}
	int ans = 0;
	for (auto &x : dict)
		ans = max(ans, x.second);
	cout << ans << endl;
}

