#define _CRT_SECURE_NO_WARNINGS
#define forn(i, a, n) for(int i = a; i < n; ++i)
#define pb push_back
#define mp make_pair
//#define f first
//#define sex second

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <set>
#include <ostream>
#include <queue>
#include <functional>
#include <sstream>
#include <map>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
#pragma comment(linker, "/STACK:228228000")
const ll mod = 9982443530;

ll n;
vector<ll> a;

ll cal(ll q)
{
	ll ret = 0;
	while (q > 0)
	{
		ret += q % 10;
		q /= 10;
	}
	return ret;
}

int main()
{
	/*

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	*/


	cin >> n;

	ll ad = 0;

	for(ll i = 1; i <= 1e13; i *= 10)
	{
		forn(j, 1, 1000)
		{
			a.push_back(j*i + ad);
		}
		ad += i * 9;
	}

	sort(a.begin(), a.end());

	vector<ll> b;
	b.push_back(a.back());

	forn(i, 1, a.size())
	{
		ll f, s;
		f = b.back();
		s = a[a.size() - 1 - i];
		if (f != s)
		{
			if(f*cal(s) >= s*cal(f))
			b.push_back(s);
		}
	}

	forn(i, 0, n)
		cout << b[b.size() - 1 - i] << endl;
	return 0;
}
