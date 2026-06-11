#include<map>
#include<set>
#include<bitset>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<chrono>
#include<stack>
#include<fstream>
#include<math.h>
#include<list>
#include<complex>
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define SIZE(a) ll(a.size())
#define vll vector<ll> 
#define MEMSET(a, n, m) for(ll i=0;i<=n;i++) a[i] = m
#define BIT(n) (ll(1)<<n)
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end()) 
#define UNIQUE_ARRAY(a,x) unique(a + 1, a + x + 1) - a - 1
#define SORT(a,n) sort(a+1,a+n+1)
#define SORT_O(a,n,order) sort(a+1,a+n+1,order)
#define PER(i,y,x) for(ll i=y;i>=x;i--)
typedef long long ll;
using namespace std;


ll const MOD = 1e9 + 7;
ll mod_p(ll x, ll y) {
	x %= MOD;
	y %= MOD;
	return (x + y + MOD) % MOD;
}

ll mod_m(ll x, ll y) {
	x %= MOD;
	y %= MOD;
	return x * y%MOD;
}

ll mod_pow(ll x, ll t) {
	x %= MOD;
	if (t == 0) {
		return 1;
	}
	else {
		ll v = mod_pow(x, t / 2);
		if (t % 2 == 0) {
			return v * v % MOD;
		}
		else {
			return v * v%MOD * x %MOD;
		}
	}
}

ll mod_inv(ll x) {
	return mod_pow(x, MOD - 2);
}

struct edge
{
	ll from; long long to; long long len;
	bool operator<(const edge& rhs) const {
		return len > rhs.len;
	}
};

map<ll, ll> mp1, mp2;

ll chll(char x) {
	return x - 'a';
}
ll const alphsize = 25;

int main() {
	ll ans;
	string s;
	cin >> s;
	ll n = SIZE(s);
	ll stt = 0;
	mp2[0] = 1;
	REP(i, 1, n) {
		char c = s[i - 1];
		ll cur = chll(c);
		stt = stt ^ BIT(cur);
		ll tmp = 1e18;
		if (mp2[stt] == 1) {
			tmp = mp1[stt];
		}
		REP(i, 0, alphsize) {
			ll now = stt ^ BIT(i);
			if (mp2[now] == 1) {
				tmp = min(tmp, mp1[now]);
			}
		}
		tmp++;
		if (mp2[stt] == 0) {
			mp2[stt] = 1;
			mp1[stt] = tmp;
		}
		else {
			mp1[stt] = min(mp1[stt], tmp);
		}
		if (i == n) {
			ans = mp1[stt];
		}
	}
	if (ans) {
		cout << ans << endl;
	}
	else {
		cout << 1 << endl;
	}
}