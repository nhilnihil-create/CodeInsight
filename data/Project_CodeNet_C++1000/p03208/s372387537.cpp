#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long int64;
const double PI = 3.14159265358979323846;
const double EPS = 1e-12;
const int INF = 1<<29;
const long long  INFL = 1e18;
const int MOD = 1000000007;
const int MAX = 210000;
const int MAX_NUM = 1000000001;
void solve() {
	int64 N, K; cin >> N >> K;
	vector<int64> h(N);
	for (int64 i = 0; i < N; ++i) {
		cin >> h[i];
	}
	sort(all(h));
	int64 ans = INFL;
	int64 slide = K - 1;
	for (int64 i = 0; i < N - K + 1; ++i) {
		ans = min(ans, h[i + slide] - h[i]);
	}
	cout << ans << endl;
	return;
}
int main() {
	solve();
	return 0;
}