#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef struct _data {
	int x;
	int y;
} data;

int  main()
{
	vector<pair<int ,int> > a(3);
	map <int , int> mp;
	rep(i, 3)
	{
		cin >> a.at(i).first >> a.at(i).second;
		mp[a.at(i).first] += 1;
		mp[a.at(i).second] += 1;
	}
	// rep(i,3)
	// {
	// 	if(abs(a.at(i).first -  a.at(i).second) != 1)
	// 	{
	// 		cout << "NO\n"; return 0;
	// 	}
	// }
	for(int i= 1; i <= 4; i++)
	{
		if (i == 1 || i == 4)
		{
			if (mp[i] != 1)
			{
				cout << "NO\n"; return 0;
			}
		}
		else
		{
			if (mp[i] != 2)
			{
				cout << "NO\n"; return 0;
			}
		}
	}
	cout << "YES\n";
	return (0);
}
