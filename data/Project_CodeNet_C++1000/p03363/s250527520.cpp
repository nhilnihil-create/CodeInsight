#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
using P = pair<int, int>;

signed main(void)
{
	int n;
	cin >> n;
	vector<ll> sum(n);
	map<ll, ll> mp;
	ll cnt;

	rep(i, n) cin >> sum[i];
	rep(i, n - 1) sum[i + 1] += sum[i];
	rep(i, n) mp[sum[i]]++;
	cnt = 0;
	for (auto p : mp)
	{
		auto k = p.first;
		auto v = p.second;
		if (k == 0)
			cnt += v;
		if (v >= 2)
			cnt += v * (v - 1) / 2;
	}
	cout << cnt << endl;
	return 0;
}
