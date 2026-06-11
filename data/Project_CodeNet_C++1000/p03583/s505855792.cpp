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
	ll n; cin >> n;
	for (ll i = 1; i <= 3500; ++i)
	{
		for (ll j = 1; j <= 3500; ++j)
		{
			ll k = 4 * i*j - j * n - i * n;
			if (k <= 0)continue;
			if ((i*j*n) % k == 0)
			{
				cout << i << " " << j << " " << (i*j*n) / k << endl;
				return 0;
			}
		}
	}
}