#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using P   = pair<ll, ll>;
using mat = vector<vector<ll>>;
typedef string::const_iterator State;
class ParseError {};

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
ll powm(ll a, ll b, ll c) {
	if (b == 0)
		return 1;
	else if (b % 2 == 0) {
		ll d = powm(a, b / 2, c);
		return (d * d) % c;
	} else
		return (a * powm(a, b - 1, c)) % c;
}
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
//ll dx[4] = {1, 0, -1, 0};
//ll dy[4] = {0, 1, 0, -1};

ll a[2002];

int main() {
	IOS();
	ll n, k, q;
	cin >> n >> k >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (q == 1) {
		dump(0);
		return 0;
	}
	ll ans = INF;
	vector<ll> tmp, unko;
	for (int i = 1; i <= n; i++) {
		ll X = a[i]; //最小値がa[i]
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			if (a[j] >= X) {
				unko.push_back(a[j]);
			} else {
				if (unko.empty()) continue;

				sort(unko.begin(), unko.end());
				for (int t = 0; t <= (int)unko.size() - k; t++) {
					tmp.push_back(unko[t]);
				}
				unko.clear();
			}
		}
		sort(unko.begin(), unko.end());
		for (int t = 0; t <= (int)unko.size() - k; t++) {
			tmp.push_back(unko[t]);
		}
		unko.clear();
		if (tmp.size() < q - 1) {
			tmp.clear();
			continue;
		}
		sort(tmp.begin(), tmp.end());
		ll Y = tmp[q - 2];
		tmp.clear();
		ans = min(ans, Y - X);
	}
	dump(ans);
	return 0;
}
