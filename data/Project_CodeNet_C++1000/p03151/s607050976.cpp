#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll LINF = 1e18;
#define y0 y3487465
#define y1 y8687969
#define j0 j1347829
#define j1 j234892
#define next asdnext
#define prev asdprev
#define MP make_pair
#define F first
#define S second
#define PB push_back
#define dump(x)  cout << #x << " = " << (x) << endl;	// debug
#define SZ(x) ((ll)(x).size())
#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define RFOR(i, a, b) for (ll i = (a); i >= (b); i--)
#define ps(s) cout << #s << endl;
#define pv(v) cout << (v) << endl;
#define pvd(v) cout << setprecision(16) << (v) << endl;
#define ALL(a)  (a).begin(),(a).end()
#define RANGE(a, left, right)  (a).begin()+(left),(a).begin()+(right)	// left to (right-1)

int main() {
	ll n;
	cin >> n;
	vector<ll> a(n);
	vector<ll> b(n);
	vector<ll> c(n);
	vector<ll> sa(n);
	int res = 0;
	FOR(i, 0, n - 1) {
		cin >> a[i];
	}
	FOR(i, 0, n - 1) {
		cin >> b[i];
	}
	FOR(i, 0, n-1) {
		if (a[i] < b[i]) {
			c[i] = b[i];
			res++;
		}
		else {
			c[i] = a[i];
			sa[i] = a[i] - b[i];
		}
	}
	ll suma = accumulate(ALL(a), 0LL);
	ll sumc = accumulate(ALL(c), 0LL);
	if (suma == sumc) {
		pv(res);
		return 0;
	}
	else {
		sort(ALL(sa));
		ll remini = sumc - suma;
		RFOR(i, n - 1, 0) {
			remini -= sa[i];
			res++;
			if (remini <= 0) {
				pv(res);
				return 0;
			}
		}
		ps(-1);
		return 0;
	}
	return 0;
}