// copied by Nurstan Duisengaliev
// skatal
#include <bits/stdc++.h>
 
#define ll long long
#define all(x) x.begin(), x.end()
#define in insert
#define mp make_pair
#define F first
#define S second
#define ppf pop_front
#define pb push_back
#define ppb pop_back
#define pf push_front
#define pii pair <int, int>
#define boost() ios_base::sync_with_stdio(0), cin.tie(0)
#define sz(x) x.size()
 
using namespace std;
 
const int N = (int)2e5 + 123;
const int mod = (int)1e9 + 7;
const ll INF = (ll)1e18 + 7;

void solve () {
	ll a, b, c;
	cin >> a >> b >> c;
	ll sum = 0;
	if (c >= b) {
		sum += b * 2;
		c -= b;
		sum += min (a, c);
		if (c > a) {
			sum ++;
		}
		cout << sum;
	}
	else {
		cout << b + c;
		return;
	}
	
}
 
main () {
//	freopen (".in", "r", stdin);
//	freopen (".out", "w", stdout);
	boost ();
	int TT = 1;
//	cin >> TT;
	while (TT --) {
		solve ();
	}
	return 0;	
}