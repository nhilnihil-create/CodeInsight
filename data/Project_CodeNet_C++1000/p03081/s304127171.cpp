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

signed main() {
	IOS();
	ll n, q;
	string s;
	cin >> n >> q >> s;
	vector<pair<char, char>> a(q);
	for (int i = 0; i < q; i++) {
		cin >> a[i].first >> a[i].second;
	}
	ll left = -1, right = n;
	while (left < right - 1) {
		ll mid = (left + right) / 2;
		ll now = mid;
		//dump(mid);
		for (int i = 0; i < q; i++) {
			if (now == -1) {
				break;
			}
			if (s[now] == a[i].first) {
				if (a[i].second == 'R')
					now++;
				else
					now--;
			}
		}
		if (now == -1) {
			left = mid;
		} else {
			right = mid;
		}
	}
	left++;
	//dump(left);
	ll left2 = -1, right2 = n + 1;
	while (left2 < right2 - 1) {
		ll mid = (left2 + right2) / 2;
		ll now = mid;
		//dump(mid);
		for (int i = 0; i < q; i++) {
			if (now == -1) {
				break;
			}
			if (s[now] == a[i].first) {
				if (a[i].second == 'R')
					now++;
				else
					now--;
			}
		}
		if (now == n) {
			right2 = mid;
		} else {
			left2 = mid;
		}
	}
	//dump(right2);
	ll unko = n - right2;
	dump(max(0ll, n - left - unko));
	return 0;
}