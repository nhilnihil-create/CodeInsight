#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
using P = pair<ll, ll>;
using V = vector<ll>;
#define rep(i, n) for(ll i=0;i<(ll)(n);i++)
#define rep1(i, n) for(ll i=1;i<=(ll)(n);i++)
#define rep2(i, m, n) for(ll i=m;i<(ll)(n);i++)
#define rrep(i, n, m) for(ll i=n;i>=(ll)(m);i--)
#define ALL(obj) (obj).begin(), (obj).end()
#define RALL(obj) (obj).rbegin(), (obj).rend()
#define MOD 1000000007
#define INF 1000000000
#define LLINF 1e18

void solve_abc_b() {
	ll n, m;
	ll a, b, c, d;
	ll x, y;
	ll k;
	ll l;
	string s, t;
	ll l_ans = 0;
	float f_ans = 0;
	string s_ans;

	cin >> d >> n;

	if (d == 0) {
		l_ans = n;
		if (n == 100) {
			l_ans = 101;
		}
	}
	else if (d == 1) {
		l_ans = 100 * n;
		if (n == 100) {
			l_ans = 10100;
		}
	}
	else if (d == 2) {
		l_ans = 10000 * n;
		if (n == 100) {
			l_ans = 1010000;
		}
	}

	cout << l_ans << "\n";

	return;
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed;
	cout << setprecision(7);

	solve_abc_b();

	return 0;
}
