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
const int MAX_NUM = 999999999;
void solve() {
	int n, m; cin >> n >> m;
	vector<int> x(m);
	vector<int> diff;
	if (n >= m) {
		cout << 0 << endl;
		return;
	}
	for (int i = 0; i < m; ++i) cin >> x[i];
	sort(all(x));
	for (int i = 0; i < (m - 1); ++i) {
		diff.push_back(abs(x[i] - x[i + 1]));
	}
	sort(all(diff));
	int64 ans = 0;
	for (int i = 0; i < diff.size() - (n - 1); ++i) {
		ans += diff[i];
	}
	cout << ans << endl;
	return;
}
int main() {
	solve();
	return 0;
}