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
	IOS();
	ll n;
	cin >> n;
	vector<ll> a(n);
	if (n == 3) {
		cout << "2 5 63" << endl;
		return 0;
	}
	if (n == 4) {
		cout << "2 5 20 63" << endl;
		return 0;
	}
	if (n == 5) {
		cout << "2 5 20 30 63" << endl;
		return 0;
	}
	ll sum = 0;
	int s2 = 0, s3 = 0, s4 = 0, s6 = 1;
	for (int i = 0; i < n; i++) {
		if (i % 4 == 0) {
			a[i] = 6 * s2 + 2;
			s2++;
		}
		if (i % 4 == 1) {
			a[i] = 6 * s3 + 3;
			s3++;
		}
		if (i % 4 == 2) {
			a[i] = 6 * s4 + 4;
			s4++;
		}
		if (i % 4 == 3) {
			a[i] = 6 * s6;
			s6++;
		}
		sum += a[i];
	}
	if (sum % 6 == 2) {
		a[4] = s6 * 6;
	}
	if (sum % 6 == 3) {
		a[5] = s6 * 6;
	}
	if (sum % 6 == 5) {
		a[5] = s4 * 6 + 4;
	}
	for (int i = 0; i < n; i++) {
		if (i) cout << " ";
		cout << a[i];
	}
	cout << endl;

}