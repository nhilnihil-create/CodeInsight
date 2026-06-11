#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <set>
using namespace std;
int cei(int a, int b) {
	return a % b == 0 ? a / b : a / b + 1;
}
int main() {
	int d, g;
	cin >> d >> g;
	int p[d], c[d];
	for (int i = 0;i < d;i++) cin >> p[i] >> c[i];
	int ans = 1000000;
	for (int i = 0;i < (1<<d);i++) {
		int cur = 0, cnt =0;
		for (int j = 0;j < d;j++) {
			if (i & (1<<j)) {
				cnt += p[j];
				cur += p[j] * (j + 1) * 100 + c[j];
			}
		}
		for (int j = d - 1;j >= 0;j--) {
			if (cur >= g) break;
			if ((i & (1<<j)) == 0) {
				cnt += min(cei(g - cur, (j + 1) * 100), p[j]);
				cur += min(cei(g - cur, (j + 1) * 100), p[j]) * (j + 1) * 100;
			}
		}
		//cout << i << " " << cnt << endl;
		ans = min(ans, cnt);
	}
	cout << ans << endl;
	return 0;
}