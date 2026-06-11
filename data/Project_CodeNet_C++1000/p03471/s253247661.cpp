#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;

int n, Y;

void solve()
{
	int c = 0;
	int x, y, z, Z;
	for (x = 0; x <= n; ++x)
	{
		for (y = 0; y <= n; ++y)
		{
			Z = Y - 10000 * x - 5000 * y;
			if (Z >= 0 && Z % 1000 < 1)
			{
				int z = Z / 1000;
				if (x + y + z == n)
				{
					cout << x << " " << y << " " << z << endl;
					return; 
				}

			}
		}
	}
	cout << "-1 -1 -1" << endl;
}

int main()
{
	cin >> n >> Y;
	solve();
}
