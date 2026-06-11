#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
using P   = pair<ll, ll>;
using mat = vector<vector<ll>>;

void IOS() { ios::sync_with_stdio(false), cin.tie(0); }

const ll INF = 1e16;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-10;

template <typename T> void dump(T x) { cout << x << endl; }
void dumpf(ld x, int t) { cout << setprecision(t) << fixed << x << endl; }
template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val) {
	fill((T *)array, (T *)(array + N), val);
}

ll mod(ll a, ll b) {
	if (a > 0) return a % b;
	if (a % b == 0) return 0;
	ll x = -a / b + 1;
	a += x * b;
	return a % b;
}

// ll dx[4] = {1, 0, -1, 0};
// ll dy[4] = {0, 1, 0, -1};

int main() {
	ll n;
	cin >> n;
	vector<ll> x(n), y(n);
	vector<ll> tmp;
	int odd;
	bool ok = true;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		if (i == 0)
			odd = mod(x[i] + y[i], 2);
		else {
			if (odd != mod(x[i] + y[i], 2)) ok = false;
		}
		if (odd == 0) x[i]--;
	}
	if (!ok) {
		dump(-1);
		return 0;
	}
	vector<ll> d;
	for (ll i = 0; i < 31; i++) {
		d.push_back(1ll << i);
	}
	dump(odd == 1 ? 31 : 32);
	if (odd == 0) cout << 1 << " ";
	for (int i = 0; i < d.size(); i++) {
		cout << d[i];
		if (i != d.size() - 1) cout << " ";
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		if (odd == 0) cout << "R";
		ll U = (x[i] + y[i] + (1ll << 31) - 1) / 2;
		ll V = (x[i] - y[i] + (1ll << 31) - 1) / 2;
		for (int j = 0; j < d.size(); j++) {
			ll t = 1ll << j;
			if ((U & t) == t && (V & t) == t) cout << "R";
			if ((U & t) == t && (V & t) != t) cout << "U";
			if ((U & t) != t && (V & t) == t) cout << "D";
			if ((U & t) != t && (V & t) != t) cout << "L";
		}
		cout << endl;
	}
	return 0;
}