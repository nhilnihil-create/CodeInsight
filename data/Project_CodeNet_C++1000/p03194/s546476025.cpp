#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <complex>
#include <tuple>

#define FAST ios_base::sync_with_stdio(false); cin.tie(0)
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define repr(i, a, b) for(int i=int(a); i>=int(b); i--)
#define reps(i,n) for(int i=1;i<=int(n);++i)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RREPS(i,x) for(int i=((int)(x));i>0;i--)
#define iceil(x,y) (x+y-1)/y
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define all(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() )
#define LF "\n"

int gcd(int a,int b){return b?gcd(b,a%b):a;}

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef pair<int, PII> PP;

ll n;
ll p;
map<ll, ll> mp;
vector<ll> idx;

void factoring(ll n)
{
    // 割る数の初期値
    ll a = 2;
    while (n >= a*a) {
        if (n % a == 0) {
			// cout << a << " * ";
			mp[a]++;
			idx.push_back(a);
            n /= a;
        } else {
            a++;
        }
    }
    // 最後に残った n は素因数
	mp[n]++;
    // cout << n << LF;
}

int main()
{
	FAST;

	cin >> n >> p;

	if (n ==1) {
		cout << p << LF;
		return 0;
	}

	factoring(p);
	
	std::sort(idx.begin(), idx.end());
	idx.erase(std::unique(idx.begin(), idx.end()), idx.end());

	ll ans=1;
	rep(i,idx.size()) {
		// cout << mp[idx[i]] << LF;
		if (mp[idx[i]] >= n) {
			ll c = mp[idx[i]]/n;
			ans *= (ll)pow(idx[i], (float)c);
		}
	}

	cout << ans << LF;

	return 0;
}