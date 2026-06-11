#include <bits/stdc++.h>
using namespace std;

int main()
{
	int x;
	cin >> x;

	if (x <= 3)
	{
		cout << 1 << endl;
		return 0;
	}

	int ans = 0;

	for (int b = 2; b * b <= x; b++)
	{
		for (int tmp = b * b; tmp <= x; tmp *= b)
		{
			ans = max(ans, tmp);
		}
	}

	cout << ans << endl;

	return 0;
}