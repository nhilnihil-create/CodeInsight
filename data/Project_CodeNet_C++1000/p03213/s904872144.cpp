#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
	int n;
	cin >> n;
	if (n < 10) {
		cout << 0 << endl;
		return 0;
	}

	vector<int> div(n + 1, 0);
	for (int i = 2; i <= n; i++) {
		int num = i;
		for (int j = 2; j <= i; j++) {
			while (num % j == 0) {
				div[j]++;
				num /= j;
			}
		}
	}

	// 24, 14, 4, 2
	vector<int> cnt(4, 0);
	rep(i, n + 1) {
		if (div[i] > 23) cnt[0]++;
		if (div[i] > 13) cnt[1]++;
		if (div[i] > 3) cnt[2]++;
		if (div[i] > 1) cnt[3]++;
	}

	int ans = 0;
	if (cnt[0] > 0) {
		ans += cnt[0] * (cnt[3] - 1);
	}
	if (cnt[1] > 0) {
		ans += cnt[1] * (cnt[2] - 1);
	}
	ans += cnt[2] * (cnt[2] - 1) / 2 * (cnt[3] - 2);
	if (div[2] > 73) ans++;
	cout << ans << endl;
}