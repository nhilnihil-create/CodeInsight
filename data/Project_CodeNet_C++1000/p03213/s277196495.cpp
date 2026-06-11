#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	vector<int> a(n + 1);
	for (int i = 2; i <= n; i++) {
		if (a[i] == 0) {
			for (int j = i * 2; j <= n; j += i) { a[j]++; }
		}
	}
	map<int, int> mp;
	for (int i = 2; i < n + 1; i++) {
		if (a[i] == 0) {
			int p = n, k = 0;
			while (p) {
				p /= i;
				k += p;
			}
			mp[i] = k;
		}
	}
	vector<int> cnt(5);
	for (auto k : mp) {
		int p = k.second;
		if (p >= 74) cnt[0]++;
		if (p >= 24) cnt[1]++;
		if (p >= 14) cnt[2]++;
		if (p >= 4) cnt[3]++;
		if (p >= 2) cnt[4]++;
	}
	int ans = cnt[0] + cnt[1] * (cnt[4] - 1) + cnt[2] * (cnt[3] - 1) + cnt[3] * (cnt[3] - 1) / 2 * (cnt[4] - 2);
	printf("%d\n", ans);
	return 0;
}