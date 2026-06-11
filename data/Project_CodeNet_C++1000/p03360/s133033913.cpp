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

const ll inf = 1ll << 60;
const ll mod = (ll)1e9 + 7;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

#define print(s) cout << s;
#define println(s) cout << s << endl;
#define printd(s, f) cout << fixed << setprecision(f) << s << endl;


int main()
{
	vector<ll> a(3);
	for (int i = 0; i < 3; i++)
	{
		cin >> a[i];
	}

	sort(rall(a));

	int k;
	cin >> k;

	for (int i = 0; i < k; i++)
	{
		a[0] *= 2;
	}

	println(accumulate(all(a), 0LL));
}
