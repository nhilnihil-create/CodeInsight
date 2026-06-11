#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using ii = pair<int, int>;
constexpr int MN = 5005;

ll p[MN], DP[MN][MN];

int main() {
    if (fopen("in", "r")) freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0);

	int N; cin >> N;
	ll A, B; cin >> A >> B;
	for (int i = 0; i < N; ++i) cin >> p[i];

	memset(DP, '?', sizeof DP);
	DP[0][0] = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j <= N; ++j) {
			if (p[i] > j) DP[i+1][j] = min(DP[i][j]+A, DP[i+1][j]), DP[i+1][p[i]] = min(DP[i][j], DP[i+1][p[i]]);
			else DP[i+1][j] = min(DP[i][j]+B, DP[i+1][j]);
		}
	}

	ll ans = 1e18;
	for (int i = 1; i <= N; ++i) ans = min(DP[N][i], ans);
	cout << ans;
}
