#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int n, ans, tmp;
	cin >> n;
	long long p[n], q[n];
	rep(i, n) 
	{
		cin >> p[i];
		p[i]--;
		q[p[i]] = i;
	}
	ans = 0;
	tmp = 1;
	rep(i, n - 1)
	{
		if (q[i] > q[i + 1]) 
		{
			ans = max(ans, tmp);
			tmp = 1;
		}
		else
			tmp++;
	}
	ans = max(tmp, ans);
	cout << n - ans << endl;
}
