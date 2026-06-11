#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int N = 5555;
long long dp[N][N];

void remin(long long& x, long long y) {
	if (x == -1 || x > y) {
		x = y;
	}
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt(), cost_r = nxt(), cost_l = nxt();
	vector<int> p(n), q(n);
	for (int i = 0; i < n; ++i) {
		p[i] = nxt() - 1;
		q[p[i]] = i;
	}

	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;
	for (int i = 1; i < n; ++i) {
		int num_less = 0, num_greater = 0;
		for (int j = 0; j < i; ++j) {
			if (p[j] < p[i]) {
				++num_less;
			} else {
				++num_greater;
			}
		}
		remin(dp[i][i], 1ll * cost_r * num_greater + 1ll * cost_l * num_less);
		for (int j = 0; j < i; ++j) {
			if (dp[i - 1][j] == -1) {
				continue;
			}
			if (p[i] < p[j]) {
				remin(dp[i][j], dp[i - 1][j] + cost_l);
			} else {
				remin(dp[i][j], dp[i - 1][j] + cost_r);
				remin(dp[i][i], dp[i - 1][j]);
			}
		}
	}

	long long ans = -1;
	for (int i = 0; i < n; ++i) {
		if (dp[n - 1][i] > -1) {
			remin(ans, dp[n - 1][i]);
		}
	}

	cout << ans << "\n";

	return 0;
}