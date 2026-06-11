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

int main() {
	IOS();
	ll h, w, n;
	cin >> h >> w >> n;
	map<P, bool> mp;
	for (int i = 0; i < n; i++) {
		ll x, y;
		cin >> x >> y;
		mp[P(x, y)] = true;
	}
	ll ymax = 1;
	for (int i = 1; i <= h; i++) {
		//dump(ymax);
		P l = P(i + 1, 1), r = P(i + 1, ymax + 1);
		if (mp.lower_bound(r) != mp.lower_bound(l)) { // x >= l ⇔ x >= r
			dump(i);								  //x方向に動かせるか
			return 0;
		}
		if (!mp[P(i + 1, ymax + 1)]) ymax++;
	}
	dump(h);
	return 0;
}
