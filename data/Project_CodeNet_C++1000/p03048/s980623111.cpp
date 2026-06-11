#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using namespace std;
using P = pair<int,int>;
typedef long long ll;

int  main()
{
	int r,g,b,n;
	cin >> r >> g >> b >> n;
	long ans = 0;
	for(int i = 0; i <= n / r; i++)
	{
		for (int j = 0; j <= n / g; j++)
		{
			if (n - ((i*r) + (j * g)) == 0)
				ans++;
			else if (n - ((i*r) + (j * g)) > 0)
			{
				if ((n - ((i*r) + (j * g))) % b == 0)
					ans++;
			}
		}
	}
	cout << ans << endl;
	return (0);
}
