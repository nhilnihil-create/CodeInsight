#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

signed main(void)
{
	ll N;
	cin >> N;
	for(int h = 1; h <= 3500; h++)
	{
		for(int n = 1; n <= 3500; n++)
		{
			if (4 * h * n - N * n - N * h > 0)
			{
				ll w = (ll)(N * h * n) / (4 * h * n - N * n - N * h);
				if ((N * h * n) % (4 * h * n - N * n - N * h) == 0 && w > 0)
				{
					cout << h << " " << n << " " << w << endl;
					return 0;
				}	
			}
		}
	}
	return 0;
}
