#define _CRT_SECURE_NO_WARNINGS
#define forn(i, a, n) for(ll i = a; i < n; i++)

#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <map>


using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

ll n, x, res, re;
ll a[200007];
ll b[200007];
set<ll> near;


ll clear(ll i)
{
	return 5 * a[i] + 2 * x;
}

ll count(ll prec)
{
	if (prec < 1 || prec > n)
		return 1e18;

	ll ret = 0;
	forn(i, 0, 200007)
		b[i] = 0;
	b[2] = prec;
	ll mi = 2;
	forn(i, n - prec, n)
		ret += clear(i);
	for (ll i = n - prec - 1; i >= 0; i--)
	{
		if (b[mi] == 0)
			mi++;
		b[mi]--;
		b[mi + 1]++;
		ret += (mi * 2 + 1)*a[i] + x;
	}
	return ret;
}

ll bin()
{
	ll le, ri;
	le = 1;
	ri = n;
	while (ri - le > 1)
	{
		ll m = (ri + le) / 2;
		ll f, s, t;
		f = count(m - 1);
		s = count(m);
		t = count(m + 1);
		if (s < f && s < t)
			return s;
		if (f < s)
			ri = m;
		else
			le = m;
	}

	ll q, w, e, r, t;
	q = count(le - 1);
	w = count(le);
	e = count(le + 1);
	r = count(ri);
	t = count(ri + 1);
	q = min(q, w);
	e = min(e, r);
	q = min(q, e);
	q = min(q, t);
	return q;
}


int main()
{
	/*
	freopen("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	*/


	cin >> n >> x;
	forn(i, 0, n)
		cin >> a[i];
	res = bin();
	cout << res;
	return 0;
}