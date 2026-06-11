#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	int n,sta = 1;
	cin >> n;
	int ans[33] = {};
	for (int i = 1; i <= 32; ++i)
	{
		ans[i] = abs(n % 2);
		sta = ((ans[i])?i:sta);
		if(i % 2 == 0 && n > 0)
		{
			++n;
		}
		else if(i % 2 == 1 && n < 0)
		{
			--n;
		}
		n /= 2;
	}
	for (int i = sta; i >= 1; --i)
	{
		cout << ans[i];
	}
	cout << endl;
	return 0;
}