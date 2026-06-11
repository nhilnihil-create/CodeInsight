#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int  main()
{
	int n,t; cin >> n >> t;
	vector<pair<int, int> > c(n);
	rep(i, n)
	{
		cin >> c[i].first >> c[i].second;
	}
	sort(c.begin(), c.end());
	rep(i, n)
	{
		if (c[i].second <= t)
		{
			cout << c[i].first << endl;
			return 0;
		}
	}
	cout << "TLE\n" ;
	return (0);
}
