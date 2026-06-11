#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int n;
	cin >> n;
	int a[n];
	map<long long, long long> mp;
	long long sum[n], cnt;

	rep(i, n) 
	{
		cin >> a[i];
		sum[i] = a[i];
	}
	rep(i, n - 1) sum[i + 1] += sum[i];
	rep(i, n) mp[sum[i]]++;
	cnt = 0;
	for(auto p : mp)
	{
		auto k = p.first;
		auto v = p.second;
		if (k == 0)
		{
			cnt += v;
		}
		cnt += v * (v - 1) / 2;
	}
	cout << cnt << endl;
	return 0;
}
