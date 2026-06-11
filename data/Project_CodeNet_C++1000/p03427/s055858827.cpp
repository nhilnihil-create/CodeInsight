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
#include <iterator>

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
	ll n;
	cin >> n;

	string s = to_string(n);

	bool b = true;

	ll res = 0;

	for (ll i = 1; i < s.length(); i++)
	{
		if (s[i] != '9')
		{
			b = false;
		}
	}
	for (ll i = 0; i < s.length() - 1; i++)
	{
		res += 9;
	}

	if (b)
	{
		res += stoll(s.substr(0, 1));
	}
	else if (n >= 10)
	{
		res += stoll(s.substr(0, 1)) - 1;
	}
	else
	{
		res = n;
	}

	println(res);
}
