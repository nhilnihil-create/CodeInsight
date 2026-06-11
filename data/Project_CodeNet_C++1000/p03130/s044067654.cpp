#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int  main()
{
	map <int , int> mp;
	rep(i, 3)
	{
		int a,b;
		cin >> a >> b;
		mp[a]++;
		mp[b]++;
	}
	for(int i= 1; i <= 4; i++)
	{
		if (mp[i] > 2)
		{
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	return (0);
}
