#include<bits/stdc++.h>
using namespace std;


int main()
{
	int D, G, p[11], c[11];
	cin >> D >> G;
	for (int i = 0; i < D; ++i)
		cin >> p[i] >> c[i];

	int ans = 1e9;
	for (int bit = 0; bit < 1 << D; ++bit)
	{
		int sum = 0, num = 0, rest = -1;
		for (int i = 0; i < D; ++i)
		{
			if (bit & 1 << i)
			{
				sum += (i + 1) * 100 * p[i] + c[i];
				num += p[i];
			}
			else 
			{
				rest = i;
			}
		}
		if (sum < G)
		{
			int x = 100 * (rest + 1);
			int need = (G - sum + x - 1) / x;
			if (need > p[rest])
			{
				continue;
			}
			num += need;
		}
		ans = min(ans, num);
	}
	cout << ans << endl;
}
