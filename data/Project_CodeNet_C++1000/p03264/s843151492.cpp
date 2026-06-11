#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef long long ll;

int  main()
{
	int k; cin >> k;
	int ans;
	if (k % 2 == 0)
	{
		ans = (k/2)*(k/2);
	}
	else
	{
		ans = (k/2)* ((k+1) / 2);
	}
	cout << ans << endl;
	return (0);
}