#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
	int n, k;  cin >> n >> k;
	string s; cin >> s;
	vector<int> cnt;
	int t = 1;
	for (int i = 1; i < n; ++i) {
		if (s[i] == s[i - 1]) ++t;
		else {
			cnt.push_back(t);
			t = 1;
		}
	}
	if (t) cnt.push_back(t);
	int ans = 0, now = 0, i;
	for (i = 0; i < min(2 * k + (s[0] == '0' ? 0 : 1), (int)cnt.size()); ++i) ans += cnt[i];
	int tmp = ans;
	for (; i < cnt.size(); ++i) {
		tmp += cnt[i];
		if (s[0] == '0' && i % 2 == 0) {
			tmp -= cnt[i - 2 * k];
			if (i != 2 * k) tmp -= cnt[i - 2 * k - 1];
		}
		else if (s[0] == '1' && (i & 1)) tmp -= cnt[i - 2 * k - 1] + cnt[i - 2 * k];
		ans = max(ans, tmp);
	}
	cout << ans << endl;

	return 0;
}