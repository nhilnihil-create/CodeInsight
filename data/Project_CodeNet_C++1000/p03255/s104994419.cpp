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
	IOS();
	ll n, x;
	cin >> n >> x;
	vector<ll> a(n), s(n + 1, 0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s[i + 1] = s[i] + a[i];
	}
	ull ans = INF;
	for (int k = 1; k <= n; k++) { // k回往復する
		ull tmp = 0;
		ll cnt  = 1;
		for (int i = n; cnt <= ceil((double)n / k); i -= k) {
			if (cnt == 1) {
				tmp += 5 * (s[i] - s[max(i - k, 0)]);
			} else {
				tmp += (2 * cnt + 1) * (s[i] - s[max(i - k, 0)]);
			}
			cnt++;
		}
		tmp += (n + k) * x;

		//dump(tmp);
		ans = min(ans, tmp);
	}
	dump(ans);
}