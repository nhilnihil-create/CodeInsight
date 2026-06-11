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
	ll n, k; cin >> n >> k;
	if (k % 2 == 1)
	{
		ll d = n / k;
		cout << d * d*d << endl;
	}
	else
	{
		ll d = n / k;
		d = d * d*d;
		n += k / 2;
		ll e = n / k;
		d += e * e*e;
		cout << d << endl;
	}
}