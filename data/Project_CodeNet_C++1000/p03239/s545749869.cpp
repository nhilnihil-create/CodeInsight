#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	int n, t;
	cin >> n >> t;
	int a, b, ans = 1145141919;
	for (int i = 0; i < n; ++i)
	{
		cin >> a >> b;
		if (b <= t)
		{
			ans = min(ans, a);
		}
	}
	if (ans == 1145141919)
	{
		cout << "TLE" << endl;
	}
	else
	{
		cout << ans << endl;
	}
	return 0;
}