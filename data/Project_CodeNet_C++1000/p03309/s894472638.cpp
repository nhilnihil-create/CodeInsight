#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	long long n, sum; cin >> n;
	long long a[n];
	vector<long long> b(n);

	sum = 0;
	rep(i, n) 
	{
		cin >> a[i];
		a[i] -= (i + 1);
		b[i] = a[i];
	}
	sort(b.begin(), b.end());
	rep(i, n)
	{
		sum += abs(a[i] - (b[n / 2]));
	}
	cout << sum << endl;
	return 0;
}
