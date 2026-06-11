#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 0; i <= (int)(n); i++)
using namespace std;
using P = pair<int,int>;
typedef long long ll;

int  main()
{
	int c[3][3];
	int x = 0;
	rep(i, 3)
	{
		rep(j, 3)
		{
			cin >> c[i][j];
			x = max(c[i][j], x);
		}
	}
	int a[3],b[3];
	a[0] = 0; /* a1を0と仮定し、残りa2~b3を決まられる */
	rep1(i, x)
	{
		rep(i, 3)
		{
			b[i] = c[0][i] - 0;
		}
	}
	for (int i = 1; i < 3; i++)
		a[i] = c[i][0] - b[0];

	rep(i, 3)
	{
		rep(j , 3)
		{
			if(c[i][j] != a[i] + b[j])
			{
				cout << "No\n";
				return 0;
			}
		}
	}
	cout << "Yes\n";
	return (0);
}
