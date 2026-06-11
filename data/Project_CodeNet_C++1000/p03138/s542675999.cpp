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
int nth_bit (int64 num, int n) {
	return (num >> n) & 1;
}
void solve() {
	int n; cin >> n;
	int64 k; cin >> k;
	vector<int64> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int64 opt_same = 0, opt_less = -INFL;
	for (int d = 40; d >= 0; --d) {
		int64 D = 1LL << d;
		int num1 = 0;
		for (int i = 0; i < n; ++i) if (nth_bit(a[i], d)) num1++;
		int num0 = n - num1;

		opt_less += (D * max(num0, num1));

		if (nth_bit(k, d)) {
			opt_less = max(opt_less, opt_same + (D * num1));
			opt_same += (D * num0);
		} else {
			opt_same += (D * num1);
		}
	}
	cout << max(opt_less, opt_same) << endl;
	return;
}
int main() {
	solve();
	return 0;
}