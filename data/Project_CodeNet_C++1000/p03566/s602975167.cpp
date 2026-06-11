#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using P   = pair<ll, ll>;
using mat = vector<vector<ll>>;

void IOS() { ios::sync_with_stdio(false), cin.tie(0); }

const ll INF = 1e16;
const ll MOD = 1e9 + 7;

ll mod(ll a) {
	if (a > 0) return a % MOD;
	if (a % MOD == 0) return 0;
	ll x = -a / MOD + 1;
	a += x * MOD;
	return a % MOD;
}

template <typename T> void dump(T x) { cout << x << endl; }
void dumpf(double x, int t) { cout << setprecision(t) << fixed << x << endl; }
template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val) {
	fill((T *)array, (T *)(array + N), val);
}
// int dx[4]    = {1, 0, -1, 0};
// int dy[4]    = {0, 1, 0, -1};
// ll pas[5001][5002];

int main() {
	IOS();
	int n;
	cin >> n;
	vector<double> vmax(40010);
	vector<ll> t(n), v(n);
	for (int i = 0; i < n; ++i) { cin >> t[i]; }
	for (int i = 0; i < n; ++i) { cin >> v[i]; }
	double T = 0;
	for (int i = 0; i < n; ++i) {
		if (i) { vmax[T] = min(v[i], v[i - 1]); }
		for (int j = 1; j < 2 * t[i]; ++j) { vmax[T + j] = v[i]; }

		T += 2 * t[i];
	}
	vector<double> ans(T + 1);
	ans[0] = ans[T] = 0;
	for (int i = 1; i <= T; ++i) { ans[i] = min(ans[i - 1] + 0.5, vmax[i]); }
	for (int i = T - 1; i >= 0; --i) { ans[i] = min(ans[i + 1] + 0.5, ans[i]); }
	// for (int i = 0; i <= T; ++i) { dump(ans[i]); }
	double sum = 0;
	for (int i = 0; i < T; ++i) { sum += (ans[i] + ans[i + 1]) * 0.25; }
	dumpf(sum, 3);
}