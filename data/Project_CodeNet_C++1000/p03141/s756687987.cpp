#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

signed main(void)
{
	int n;
	vector<long long> a, b;
	long long sum;

	cin >> n;
	a.resize(n);
	b.resize(n);
	sum = 0;
	rep(i, n)
	{
		cin >> a[i] >> b[i];
		a[i] += b[i];
		sum += b[i];
	}
	sum *= -1;
	sort(a.rbegin(), a.rend());
	for(int i = 0; i < n; i+=2)
		sum += a[i];
	cout << sum << endl;
	return 0;
}
