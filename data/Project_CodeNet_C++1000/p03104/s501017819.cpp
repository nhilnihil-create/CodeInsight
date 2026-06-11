#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

using namespace std;

#pragma GCC optimize("03")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define arctan atan
#define arccos acos
#define arcsin asin
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define vt vector
#define pr pair
#define u_map unordered_map
#define endl "\n"
typedef double db;			typedef long long ll;		typedef long double ld;			typedef string str;
typedef pr<int, int> pii;	typedef pr<ll,ll> pll;		typedef pr<ld,ld> pdd;
typedef vt<int> vi;			typedef vt<ll> vll;			typedef vt<bool> vb;
typedef vt<str> vs;			typedef vt<pii> vpii;		typedef vt<pll> vpll;
typedef map<int, int> mii;	typedef map<int, bool> mib;	typedef map<int, str> mis;		typedef map<int, char> mic;
typedef complex<db> cpx;	typedef vt<cpx> vcpx;
ll f(ll x)
{
	if (x < 1) return 0LL;
	ll res[] = {x,1,x+1,0};
	return res[x%4LL];
}

ll xor_range(ll a, ll  b)
{
	return (f(b) ^ f(a-1));
}
void input()
{
	ll l,r;
	cin >> l >> r;
	cout << xor_range(l,r);
}

signed main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	input();
	return 0;
}