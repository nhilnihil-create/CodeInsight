//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("trapv")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
using pi = pair<ll, ll>;
const ll mod = 7 * 17 * (1 << 23) + 1;
const ll inf = 1e18 + 69;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a < b || d < b) {
		cout << "No\n";
		return;
	};
	c = c - b + 1;
	if (c < 0) {
		ll x = __gcd(b, d);
		ll tc=c-(c%x)+(a%x);
		while(tc < c)
			tc+=x;
		while(tc-x >= c)
			tc-=x;
		c=tc;
		if (c < 0) {
			cout << "No\n";
			return;
		};
	}
	cout << "Yes\n";
}
int main() { //DINIC ORZ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll t;
	cin >> t;
	while (t--)
		solve();
}
