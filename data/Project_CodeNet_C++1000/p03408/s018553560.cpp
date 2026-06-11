#include<bits/stdc++.h>
using namespace std;

map<string, int> mp;

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s; cin >> s;
		mp[s]++;
	}

	int m; cin >> m;
	for (int i = 0; i < m; i++)
	{
		string s; cin >> s;
		mp[s]--;
	}

	int maxv = 0;
	for (auto p : mp)
	{
		maxv = max(maxv, p.second);
	}

	cout << maxv << endl;

	return 0;
}
