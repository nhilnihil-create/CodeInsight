#pragma region
#define _USE_MATH_DEFINES
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
#include <iomanip>
#include <cstdint>
#include <cstdlib>

using namespace std;
typedef long long ll;
//#define rep(i, s, e) for (int(i) = (s); (i) < (e); ++(i))
#define rep(i, e) for (int(i) = 0; (i) < (e); ++(i))
#define rrep(i, s) for (int(i) = (s) - 1; (i) >= 0; --(i))
#define all(x) x.begin(),x.end()
#pragma endregion


int main()
{
	int n, m; cin >> n >> m;
	vector<ll> x(n), y(n), z(n);
	rep(i, n)cin >> x[i] >> y[i] >> z[i];
	ll res = -1e18;
	rep(i, 8)
	{
		int a, b, c;
		a = b = c = 1;
		if (i&(1 << 0))a = -1;
		if (i&(1 << 1))b = -1;
		if (i&(1 << 2))c = -1;
		vector<ll> d;
		rep(j, n)
		{
			ll tmp = x[j] * a + y[j] * b + z[j] * c;
			d.push_back(tmp);
		}
		sort(all(d), greater<ll>());
		ll sum = 0;
		rep(j, m)sum += d[j];
		res = max(res, sum);
	}
	cout << res << endl;
}