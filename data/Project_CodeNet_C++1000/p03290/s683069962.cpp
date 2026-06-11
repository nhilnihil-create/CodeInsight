#include<bits/stdc++.h>
using namespace std;


int main()
{
	int d, g, p[11], c[11]; cin >> d >> g;
	for (int i = 0; i < d; ++i)
		cin >> p[i] >> c[i];
	int ans = 1e9;
	for (int i = 0; i < 1 << d; ++i)
	{
		int sum = 0, num = 0, rest = -1;
		for (int j = 0; j < d; ++j)
		{
			if (i & 1 << j)
			{
				sum += (j+1)*100*p[j]+c[j];
				num += p[j];
			}
			else
			{
				rest = j;
			}
		}
		if (sum < g)
		{
			int x = (rest+1)*100;
			int need = (g-sum+x-1)/x;
			if (need > p[rest])
				continue;
			num += need;
		}
		ans = min(ans, num);
	}
	cout << ans << endl;
}

