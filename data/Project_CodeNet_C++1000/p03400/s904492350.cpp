#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	int n, d, x;
	cin >> n >> d >> x;
	int a, ans = x;
	for (int i = 0; i < n; ++i)
	{
		cin >> a;
		ans += d / a + (d % a != 0);
	}
	cout << ans << endl;
	return 0;
}