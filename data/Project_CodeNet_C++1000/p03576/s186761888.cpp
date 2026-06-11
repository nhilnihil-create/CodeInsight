#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("avx2")
#define io_init cin.tie(0);ios::sync_with_stdio(0);cout<<setprecision(20)
#include <bits/stdc++.h>
constexpr int INF = 2147483647;
constexpr long long int INF_LL = 9223372036854775807;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979323846;
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

// -10 -10
// 10 10
// -9 9
// 9 -9
// -9 -9 10 10
int main() {
	int N, K;
	cin >> N >> K;
	vector<ll> x(N), y(N);
	for (int i = 0; i < N; i++)cin >> x[i] >> y[i];
	ll ans = INF_LL;
	for (int i = 0; i < N; i++)for (int j = 0; j < N; j++) {
		for (int k = 0; k < N; k++)for (int s = 0; s < N; s++) {
			ll xmax = max(x[i], x[j]), xmin = min(x[i], x[j]), ymax = max(y[k], y[s]), ymin = min(y[k], y[s]);
			int cnt = 0;
			for (int t = 0; t < N; t++) {
				if (xmin <= x[t] && x[t] <= xmax && ymin <= y[t] && y[t] <= ymax)cnt++;
			}
			if (cnt >= K)ans = min(ans, abs(xmax - xmin) * abs(ymax - ymin));
		}
	}
	cout << ans << endl;
}