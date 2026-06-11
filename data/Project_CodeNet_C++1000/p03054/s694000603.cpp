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

//ll dx[4] = {1, 0, -1, 0};
//ll dy[4] = {0, 1, 0, -1};
ll h, w, n;
ll sr, sc;
string s, t;

int main() {
	IOS;
	ll h, w, n;
	ll sr, sc;
	string s, t;
	cin >> h >> w >> n;
	cin >> sr >> sc >> s >> t;
	bool ok = false;
	ll now  = sc;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'R') now++;
		if (now > w) ok = true;
		if (t[i] == 'L' && now > 1) now--;
	}
	now = sr;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'D') now++;
		if (now > h) ok = true;
		if (t[i] == 'U' && now > 1) now--;
	}
	now = sc;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'L') now--;
		if (now < 1) ok = true;
		if (t[i] == 'R' && now < w) now++;
	}
	now = sr;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'U') now--;
		if (now < 1) ok = true;
		if (t[i] == 'D' && now < h) now++;
	}
	dump(!ok ? "YES" : "NO");
	return 0;
}