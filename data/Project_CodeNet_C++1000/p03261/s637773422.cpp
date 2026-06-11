#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	int n;
	bool ok = 1;
	string s[100];
	map<string, int> used;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> s[i];
		if (used[s[i]])
		{
			ok = 0;
		}
		++used[s[i]];
	}
	for (int i = 1; i < n; ++i)
	{
		if (s[i-1][s[i-1].size()-1] != s[i][0])
		{
			ok = 0;
		}
	}
	cout << (ok?"Yes":"No") << endl;
	return 0;
}