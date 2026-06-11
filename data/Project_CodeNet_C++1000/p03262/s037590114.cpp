#include <bits/stdc++.h>
using namespace std;
 
int gcd(int x, int y)
{
	if(x == 0)
	{
		return y;
	}
	else
	{
		return gcd(y%x, x);
	}
}
 
int main()
{
	int n, x;
	cin >> n >> x;
	int a[100000];
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		a[i] = abs(a[i] - x);
	}
	int ans = a[0];
	for (int i = 1; i < n; ++i)
	{
		ans = gcd(ans, a[i]);
	}
	cout << ans << endl;
	return 0;
}