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
const int MAX_N = 1007;
//const int MAX_K = MAX_N*(MAX_N-1) / 2;
ll a[MAX_N];
int n,k, last = 40;
vll beauty;

void make_beauties()
{
	for(int i = 1; i < n+1; ++i)
	{
		ll sum = 0;
		for(int j = i; j < n+1; ++j)
		{
			sum += a[j];
			beauty.pb(sum);
		}
		
	}
}

ll MAX_AND()
{
	ll ans = 0, i = 39;
	for(vll temp; i > -1; --i)
	{
		ll cunt = 0;
		for(ll& j: beauty)
		{
			if (j & (1LL << i)) ++cunt;
		}
		
		if (cunt >= k)
		{
			ans |= (1LL << i); temp.clear();
			for(ll j : beauty)
			{
				if (j & (1LL << i)) temp.pb(j);
			}
			beauty = temp;
		}
	}
	return ans;
}

void input()
{
	cin >> n >> k;
	for(int i = 1; i < n+1; ++i)
	{
		cin >> a[i];
	}
	make_beauties();
	cout << MAX_AND();
}

signed main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	input();
	return 0;
}
