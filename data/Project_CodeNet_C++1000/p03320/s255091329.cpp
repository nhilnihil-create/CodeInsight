#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using P   = pair<ll, ll>;
using mat = vector<vector<ll>>;

void IOS() { ios::sync_with_stdio(false), cin.tie(0); }

const ll INF = 1e16;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-12;

template <typename T>
void dump(T x) { cout << x << endl; }
void dumpf(ld x, int t) { cout << setprecision(t) << fixed << x << endl; }
template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val) {
	fill((T *)array, (T *)(array + N), val);
}
inline ll mod(ll a, ll b) {
	if (a > 0) return a % b;
	if (a % b == 0) return 0;
	ll x = -a / b + 1;
	a += x * b;
	return a % b;
}
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

// ll dx[4] = {1, 0, -1, 0};
// ll dy[4] = {0, 1, 0, -1};

ll s(ll x) {
	ll ans = 0;
	while (x) {
		ans += x % 10;
		x /= 10;
	}
	return ans;
}

ld f(ll x) {
	return (ld)x / s(x);
}

signed main() {
	IOS();
	ll k;
	cin >> k;
	vector<pair<ll, ld>> tmp;
	vector<ll> ans;
	for (int i = 1; i <= 9; i++) {
		tmp.emplace_back(i, 1);
	}
	ll d10 = 10;
	ll n   = 19;
	while (n < 1e15) {
		//cout << n << " " << s(n) << endl;
		tmp.emplace_back(n, f(n));
		n += d10;
		if ((ld)n / (n + d10) > (ld)s(n) / (s(n) + 1)) {
			d10 *= 10;
			n = ((n + 1) / d10 + 1) * d10 - 1;
		}
	}
	ll m = tmp.size();
	//return 0;
	for (int i = 0; i < m; i++) {
		bool ok = true;
		for (int j = i; j < m; j++) {
			if (tmp[i].second > tmp[j].second) ok = false;
		}
		if (ok) ans.push_back(tmp[i].first);
	}
	//dump(ans.size());
	for (int i = 0; i < k; i++) {
		dump(ans[i]);
	}
	return 0;
}