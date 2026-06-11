#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <utility>
#include <numeric>

using namespace std;

using ll = long long;
using ull = unsigned long long;

const ll inf = (ll)1e9 + 1;
const ll mod = (ll)1e9 + 7;

int main()
{
	ll n, x, y;
	cin >> n >> x >> y;

	vector<ll> a(n);

	for (int i = 0; i < n; i++)
	{
		cin >> a.at(i);
	}

	ll ans = -1;
	if (n == 1)
	{
		ans = abs(a.at(0) - y);
	}
	else
	{
		ans = max(abs(a.back() - y), abs(a.back() - a.at(n - 2)));
	}

	cout << ans << endl;


}