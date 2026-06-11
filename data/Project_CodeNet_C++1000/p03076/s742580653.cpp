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

void solve_abc_b() {
	ll n, m;
	ll x, y;
	ll a, b, c;
	ll k;
	ll l;
	string s, t;
	ll l_ans = 0;
	float f_ans = 0;
	string s_ans;

	n = 5;
	V d(n);
	rep(i, n) cin >> d[i];

	ll idx = 0;
	ll val = 10;
	rep(i, n) {
		if (d[i] % 10 == 0)continue;

		if (val > (d[i] % 10)) {
			idx = i;
			val = d[i] % 10;
		}
	}

	rep(i, n) {
		if (i == idx) continue;

		if (d[i] % 10 == 0) {
			l_ans += d[i];
		}
		else {
			l_ans += (d[i] / 10) * 10 + 10;
		}
	}

	l_ans += d[idx];

	cout << l_ans << "\n";
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed;
	cout << setprecision(7);

	solve_abc_b();

	return 0;
}
