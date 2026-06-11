#pragma region
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue> 
#include <stack>
#include <set>
#include <list>

using namespace std;
typedef long long ll;
//#define rep(i, s, e) for (int(i) = (s); (i) < (e); ++(i))
#define rep(i, e) for (int(i) = 0; (i) < (e); ++(i))
#define rrep(i, s) for (int(i) = (s) - 1; (i) >= 0; --(i))
#define all(x) x.begin(),x.end()
#pragma endregion


int main()
{
	int n, k; cin >> n >> k;
	vector<pair<ll, ll>> v(n);
	rep(i, n)
	{
		ll x, y; cin >> x >> y;
		v[i] = make_pair(x, y);
	}
	sort(all(v));
	ll res = 5e18;
	rep(i, n - k + 1)for (int j = i + k - 1; j < n; ++j)
	{
		ll x = v[j].first - v[i].first;
		vector<ll> z;
		for (int a = i; a <= j; ++a)
		{
			z.push_back(v[a].second);
		}
		sort(all(z));
		ll y = 1e10;
		rep(a, z.size() - k + 1)
		{
			y = min(y, z[a + k - 1] - z[a]);
		}
		res = min(res, x*y);
	}
	cout << res << endl;
}