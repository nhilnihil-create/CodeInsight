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
template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val) {
	fill((T *)array, (T *)(array + N), val);
}
// int dx[4]    = {1, 0, -1, 0};
// int dy[4]    = {0, 1, 0, -1};
// ll pas[5001][5002];

int main() {
	IOS();
	string s;
	cin >> s;
	int n = s.size();

	ll cnt[3] = {};
	for (int i = 0; i < n; ++i) { cnt[s[i] - 'a']++; }
	ll m = INF, M = 0;
	for (int i = 0; i < 3; ++i) {
		M = max(M, cnt[i]);
		m = min(m, cnt[i]);
	}

	dump(M - m <= 1 ? "YES" : "NO");
	return 0;
}