#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define f first
#define se second
#define pll pair<ll, ll>
#define pii pair<int, int>


using namespace std;

const int N = 2e5 + 123;
const ll mod = 1e9 + 7;
const ll inf = 1e18;
const int p = 1e9 + 7;


ll md(ll x, ll y) {
	x %= y;
	return (x + 2 * y) % y;
}


ll gcd(ll x, ll y) {
	if (x != 0 && y != 0)	
		return gcd(y, x % y);
	return x + y;
}


ll a, b, c, d;


int main() {
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
// 	freopen("input.txt", "r", stdin);
	ll test;
	cin >> test;
	while (test--) {
		cin >> a >> b >> c >> d;
		if (b > a || b > d) {
			cout << "No\n";
			continue;
		}
		ll tmp = gcd(max(b, d), min(b, d)), t, mn, t1, pls;
		t = md(a, tmp);
		mn = c - b + 1;
		t1 = md(mn, __gcd(b, d));
		if (t < t1)
			pls = __gcd(b, d) - t1 + t;
		else if (t > t1)
			pls = t - t1;
		else
			pls = 0;
		if (mn + pls >= 0)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}
