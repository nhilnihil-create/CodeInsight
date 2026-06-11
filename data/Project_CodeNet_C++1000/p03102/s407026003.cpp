#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	int n, m, c;
	cin >> n >> m >> c;
	int b[21];
	for (int i = 0; i < m; ++i)
	{
		cin >> b[i];
	}
	int a, now, ans = 0;
	for (int i = 0; i < n; ++i)
	{
		now = 0;
		for (int j = 0; j < m; ++j)
		{
			cin >> a;
			now += a * b[j];
		}
		ans += (now > -c);
	}
	cout << ans << endl;
	return 0;
}