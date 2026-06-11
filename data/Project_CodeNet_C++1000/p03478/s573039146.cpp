#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, a, b;
	cin >> n >> a >> b;

	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int d = 0;
		for (int j = i; j; j /= 10)
		{
			d += j % 10;
		}

		if (a <= d && d <= b)
		{
			ans += i;
		}
	}

	cout << ans << endl;

	return 0;
}