#include <bits/stdc++.h>
using namespace std;

signed main(void)
{
	int a;
	map<int, int> m;
	

	for(int i = 0; i < 3; i++)
	{
		cin >> a;
		m[a]++;
	}
	for(auto p: m)
	{
		if (p.second == 1)
		{
			cout << p.first << endl;
			return 0;
		}
	}
	return 0;
}
