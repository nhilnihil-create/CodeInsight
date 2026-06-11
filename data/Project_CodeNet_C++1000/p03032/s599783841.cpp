#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

signed main(void)
{
	int n, k;
	cin >> n >> k;
	int v[n];
	ll ans;

	rep(i, n) cin >> v[i];
	ans = 0;
	for(int l = 0; l <= k; l++)
	{
		for(int r = 0; r + l <= k; r++)
		{
			if (l + r > n) continue;

			vector<int> vec;
			ll sum = 0;
			rep(i, l)
			{
				sum += v[i];
				vec.push_back(v[i]);
			}
			rep(i, r)
			{
				sum += v[n - 1 - i];
				vec.push_back(v[n - 1 - i]);
			}
			sort(vec.begin(), vec.end());
			for(int i = 0; i < k - l - r; i++)
			{
				if (i >= vec.size()) break;
				if (vec[i] < 0)
					sum -= vec[i];
			}
			ans = max(ans, sum);
		}
	}
	cout << ans << endl;
	return 0;
}
