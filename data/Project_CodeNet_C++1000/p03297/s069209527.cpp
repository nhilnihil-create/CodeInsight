#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
#define rep(i,a,b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> P;
typedef complex<double> com;
const int mod = 1e9 + 7;
const int MOD = 998244353;
const int inf = 2e9;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}

void solve() {
	ll a, b, c, d; cin >> a >> b >> c >> d;
	if (b > a) {
		printf("No\n"); return;
	}
	if (b > d) {
		printf("No\n"); return;
	}
	if (b <= c) {
		printf("Yes\n"); return;
	}
	ll flag = b - gcd(b, d) + (a % gcd(b, d));
	if (flag > c) printf("No\n");
	else printf("Yes\n");
}

int main() {
	int t; cin >> t;
	rep(i, 0, t) {
		solve();
	}
	return 0;
}
