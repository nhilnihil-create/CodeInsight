#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using namespace std;
using P = pair<int,int>;
typedef long long ll;

int  main()
{
	int h,w;
	cin >> h >> w;
	string s[h];
	rep(i, h)
	{
		cin >> s[i];
	}
	string ans = "Yes";
	rep(i, h)
	{
		rep(j, w)
		{
			if (s[i][j] == '#')
			{
				if (s[i][j + 1] != '#' && s[i][j-1] != '#' && s[i-1][j] != '#' && s[i+1][j] != '#')
				{
					cout << "No" << endl;
					return 0;
				}
			}
		}
	}
	cout << ans << endl;	
	return (0);
}
