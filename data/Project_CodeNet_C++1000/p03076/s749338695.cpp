#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	int a[5];
	int mi1 = 10000, mic = 1000;
	for (int i = 0; i < 5; ++i)
	{
		cin >> a[i];
		if (a[i] % 10 != 0 && mi1 > a[i]%10)
		{
			mi1 = a[i] % 10;
			mic = i;
		}
	}
	int ans = 0;
	for (int i = 0; i < 5; ++i)
	{
		if (i == mic)
		{
			ans += a[i];
		}
		else
		{
			ans += ((a[i] + 9) / 10) * 10;
		}
	}
	cout << ans << endl;
 
 
	return 0;
}