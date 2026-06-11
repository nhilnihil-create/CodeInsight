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
	int n; cin >> n;
	ll c; cin >> c;
	vector<pair<ll,ll>> x(n); rep(i, n)cin >> x[i].first >> x[i].second;
	vector<ll> sum(n + 1), rsum(n + 1);
	rep(i, n)sum[i + 1] += sum[i] + x[i].second;
	rrep(i, n)rsum[i] += rsum[i + 1] + x[i].second;
	vector<ll> mx(n), rmx(n);
	mx[0] = max(0LL, x[0].second - x[0].first);
	rmx[n - 1] = max(0LL, x[n - 1].second - (c - x[n - 1].first));
	rep(i, n - 1)mx[i + 1] = max(mx[i], sum[i + 2] - x[i + 1].first);
	rrep(i, n - 1)rmx[i] = max(rmx[i + 1], rsum[i] - (c - x[i].first));
	ll res = 0;
	rep(i, n)
	{
		if (i == n - 1)res = max(res, mx[i]);
		else res = max(res, mx[i] - x[i].first + rmx[i + 1]);
	}
	rrep(i, n)
	{
		if (i == 0)res = max(res, rmx[0]);
		else res = max(res, rmx[i] - (c - x[i].first) + mx[i - 1]);
	}
	cout << res << endl;
}