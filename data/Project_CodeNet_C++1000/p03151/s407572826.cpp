#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int n;
	cin >> n;
	vector<int> a(n), b(n), sum;
	long long cnt, s;

	cnt = s = 0;
	rep(i, n) cin >> a[i];
	rep(i, n) 
	{
		cin >> b[i];
		if (a[i] < b[i])
		{
			s += b[i] - a[i];
			cnt++;
		}
	}
	if (s <= 0)
	{
		cout << cnt << endl;
		return 0;
	}
	rep(i, n)
	{
		if (a[i] > b[i])
			sum.push_back(a[i] - b[i]);
	}
	if (sum.size() != 0)
	{
		sort(sum.rbegin(), sum.rend());
		rep(i, sum.size())
		{
			s -= sum[i];
			cnt++;
			if (s <= 0)
			{
				cout << cnt << endl;
				return 0;
			}
		}
	}
	cout << -1 << endl;
	return 0;
}
