#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 310;
int n, a[4];
double dp[N][N][N];

double solve(int one, int two, int three) {
    if (one < 0 || two < 0 || three < 0) {
		return 0;
	}
	if (one == 0 && two == 0 && three == 0) {
		return 0;
	}
	if (dp[one][two][three] != -1.0) {
		return dp[one][two][three];
	}
	double &ret = dp[one][two][three];
	double rem = one + two + three;
	double val = n + one * solve(one - 1, two, three) + two * solve(one + 1, two - 1, three) + three * solve(one, two + 1, three - 1);
	return ret = val / rem;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }
    for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			fill_n(dp[i][j], N, -1.0);
		}
	}
    double ans = solve(a[1], a[2], a[3]);
    cout << fixed << setprecision(12) << ans;

	return 0;
}
