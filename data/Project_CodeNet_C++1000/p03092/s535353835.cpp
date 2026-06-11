#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define db double
#define pb push_back
#define ppb pop_back
#define F first
#define S second
#define mp make_pair
#define all(x) (x).begin(), (x).end()

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 5003;
int n, a, b, p[N], ind[N], fen[N];
ll dp[N];

void upd(int x, int y) {
	for (; x <= n + 1; x |= (x + 1)) {
		fen[x] += y;
	}
}

int get(int x) {
	int res = 0;
	for (; x >= 0; x = (x & (x + 1)) - 1) {
		res += fen[x];
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif
	
	cin >> n >> a >> b;
	p[0] = 0;
	p[n + 1] = n + 1;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		ind[p[i]] = i;
	}
	ind[0] = 0;
	ind[n + 1] = n + 1;
	memset(& dp, 0x3f, sizeof(dp));
	dp[0] = 0;
	for (int i = 1; i <= n + 1; i++) {
		for (int j = p[i] - 1; j >= 0; j--) {
			if (ind[j] < i) {
				ll inner = get(i - 1) - get(ind[j]);
				ll l = get(ind[j]);
				ll r = get(n + 1) - get(i);
				dp[i] = min(dp[i], dp[ind[j]] + inner * min(a, b) + l * a + r * b);
			}
			upd(ind[j], 1);
		}
		for (int j = p[i] - 1; j >= 0; j--) {
			upd(ind[j], -1);
		}
	}
	cout << dp[n + 1];
}
