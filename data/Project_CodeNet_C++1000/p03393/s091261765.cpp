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
	string s;
	cin >> s;

	vector<bool> a(26);
	for (char it : s)
	{
		a[it - 'a'] = true;
	}

	for (ll i = 0; i < 26; i++)
	{
		if (!a[i])
		{
			println((s + (char)('a' + i)));
			return 0;
		}
	}

	string t = s;
	string res;
	if (!next_permutation(all(t)))
	{
		res = "-1";
	}
	else
	{
		for (ll i = 0; i < s.length(); i++)
		{
			res = res + t[i];
			if (s[i] != t[i])
			{
				break;
			}
		}
	}

	println(res);
}


