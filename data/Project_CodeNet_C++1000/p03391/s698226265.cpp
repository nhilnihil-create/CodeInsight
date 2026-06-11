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
	ll res = 0;
	ll sum = 0;
	bool ok = true;
	vector<ll> a(n), b(n), c;
	rep(i, n)
	{
		cin >> a[i] >> b[i];
		sum += a[i];
		if (a[i] > b[i])c.push_back(b[i]);
	}
	if (c.size() == 0)
	{
		cout << 0 << endl;
		return 0;
	}
	sort(all(c));
	cout << sum - c[0] << endl;
}