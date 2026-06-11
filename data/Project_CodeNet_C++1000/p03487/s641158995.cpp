#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <iomanip>
#include <unordered_map>

using namespace std;
typedef long long  ll;

int main()
{
	ll N;
	cin >> N;
	vector<ll> a(N);
	for (ll i = 0; i < N; i++)
	{
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	ll target = a[0];
	ll num = 0;
	ll ans = 0;
	for (ll i = 0; i < N; i++)
	{
		if (target == a[i])
			num++;
		else
		{
			if (target != num)
			{
				if (target < num)
					ans += num - target;
				else
					ans += num;
			}
			target = a[i];
			num = 1;
		}
	}
	if (target != num)
	{
		if (target < num)
			ans += num - target;
		else
			ans += num;
	}
	cout << ans << endl;
	return 0;
}