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
	vector<ll> a(n); rep(i, n)cin >> a[i];
	reverse(all(a));
	if (a[0] != 2)
	{
		cout << -1 << endl;
		return 0;
	}
	ll mn = 2;
	ll mx = 3;
	for (int i = 1; i < n; ++i)
	{
		if (mx < a[i])
		{
			cout << -1 << endl;
			return 0;
		}
		mx = (mx / a[i] + 1)*a[i] - 1;
		if (mx == -1)
		{
			cout << -1 << endl;
			return 0;
		}
		if (mn < a[i])mn = a[i];
		else mn = ((mn + a[i] - 1) / a[i]) * a[i];
		if (mn > mx)
		{
			cout << -1 << endl;
			return 0;
		}
	}
	cout << mn << " " << mx << endl;
}