#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	double t, a, h, now, min = 100000;
	int n, ans;
	cin >> n >> t >> a;
	for (int i = 0; i < n; ++i)
	{
		cin >> h;
		now = abs(a - (t - h * 0.006));
		if (now < min)
		{
			min = now;
			ans = i + 1;
		}
	}
	cout << ans << endl;
	return 0;
}