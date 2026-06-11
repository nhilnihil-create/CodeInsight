#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int n, k, cnt;
	cin >> n >> k;
	vector<int> a(n);
	
	rep(i, n) cin >> a[i];
	sort(a.begin(), a.end());
	cnt = 0;
	for (int i = 1; i < n; i++)
	{
		if (a[0] == a[i]) cnt++;
	}
	n -= cnt + 1;
	if (n < k)
		cnt = 1;
	else
	{
		cnt = n / (k - 1);
		if (n % (k - 1) != 0)
			cnt++;
	}
	cout << cnt << endl;
	return 0;
}
