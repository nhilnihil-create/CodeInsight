#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;

const double PI = 3.1415926535897932384626433832795;
const ll MOD = 1000000007;

const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { -1, 0, 1, 0 };

int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }
int lcm(int x, int y) { return x / gcd(x, y) * y; }
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }

void add(ll &a, ll b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> c(n);
	for (auto &v : c) {
		cin >> v;
	}

	vector<vector<int>> places(210000);
	for (int i = 0; i < n; i++) {
		places[c[i]].push_back(i);
	}

	vector<ll> dp(210000);
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		add(dp[i], dp[i - 1]);

		int color = c[i - 1];
		int it = lower_bound(places[color].begin(), places[color].end(), i - 1)
			- places[color].begin();

		if (it <= 0) {
			continue;
		}

		int j = places[color][it - 1];
		if ((i - 1) - j > 1) {
			add(dp[i], dp[j + 1]);
		}
	}

	cout << dp[n] << endl;
	return 0;
}
