#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 200100

ll tr[4 * sz];
ll h[sz]; ll b[sz];

void upd(ll s, ll e, ll i, ll idx, ll v)
{
	if (s > i || e < i)
		return;
	if (s == e)
	{
		tr[idx] = v;
		return;
	}
	ll m = (s + e) / 2;
	upd(s, m, i, 2 * idx, v);
	upd(m + 1, e, i, 2 * idx + 1, v);
	tr[idx] = max(tr[2 * idx], tr[2 * idx + 1]);
}

ll que(ll s, ll e, ll qs, ll qe, ll idx)
{
	if (qs > e || qe < s || qs > qe)
		return 0;
	if (qs <= s && qe >= e)
		return tr[idx];
	ll m = (s + e) / 2;
	ll a = que(s, m, qs, qe, 2 * idx);
	ll b = que(m + 1, e, qs, qe, 2 * idx + 1);
	return max(a, b);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	ll n; cin >> n;

	for (ll i = 0; i < n; ++i)
		cin >> h[i];

	for (ll i = 0; i < n; ++i)
	{
		ll x; cin >> x;
		ll ans = que(0, n, 0, h[i] - 1, 1);
		upd(0, n, h[i], 1, ans + x);
	}

	cout << tr[1];

	return 0;
}