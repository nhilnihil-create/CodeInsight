#include <bits/stdc++.h>

using namespace std;

using ll = int64_t;
using Vi = vector<int>;
using Vl = vector<ll>;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

constexpr int I_INF = INT_MAX;
constexpr ll L_INF = LLONG_MAX;

//===




int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, m, d;
	cin >> n >> m >> d;

	double ans;

	if (d == 0) {
		ans = (double)(m - 1) / n;
	}
	else {
		ans = (double)2 * (n - d) * (m - 1) / ((double)n * n);
	}

	cout << setprecision(9) << ans << "\n";

	return 0;
}