#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int n, H;
	cin >> n;
	int x[n], y[n], h[n];
	bool ok;

	rep(i, n) cin >> x[i] >> y[i] >> h[i];
	for(int i = 0; i <= 100; i++)
	{
		for(int j = 0; j <= 100; j++)
		{
			int needH = -1;
			ok = true;
			rep(k, n)
			{
				if (h[k] > 0)
				{
					int tmp = h[k] + abs(i - x[k]) + abs(j - y[k]);
					if (needH == -1)
					{
						H = tmp;
						needH = -2;
					}
					else 
					{
						needH = 0;
						if (H != tmp)
							ok = false;
					}
				}	
			}
			if (ok && !needH)
			{
				cout << i << " " << j << " " << H << endl;
				return 0;
			}
			if (needH == -2)
			{
				rep(k, n)
				{
					if (h[k] > 0)
					{
						cout << x[k] << " " << y[k] << " " << h[k] << endl;
						return 0;
					}
				}
			}
		}
	}
	return 0;
}
