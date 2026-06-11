#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int r, g, b, n;
	int i, j;
	int cnt;
	cin >> r >> g >> b >> n;
	cnt = 0;
	i = j = 0; 
	while (r * i <= n)
	{
		j = 0;
		while (r * i + g * j <= n)
		{
			if (n - r * i - g * j < 0) continue;
			if ((n - r * i - g * j) % b == 0) cnt++;
			j++;
		}
		i++;
	}
	cout << cnt << endl;
	return 0;
}
