#include <bits/stdc++.h>

using namespace std;

#define intt long long
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N = 105;

int n;

int main() {

	FAST;

	cin >> n;
	vector <int> cnt(n + 1), num(N);
	for (int i = 2; i <= n; i ++) {
		int tmp = i;
		for (int j = 2; j * j <= i; j ++) {
			if (tmp % j == 0) {
				while (tmp % j == 0) {
					cnt[j] ++;
					tmp /= j;
				}
			}
		}
		if (tmp != 1) cnt[tmp] ++;
	}
	for (int i = n; i >= 0; i --) {
		num[i] = num[i + 1];
		for (int j = 1; j <= n; j ++) {
			if (cnt[j] == i) num[i] ++;
		}
	}
	int ans = num[74];
	ans += num[24] * (num[2] - 1);
	ans += num[14] * (num[4] - 1);
	ans += num[4] * (num[4] - 1) / 2 * (num[2] - 2);
	cout << ans << '\n';
	return 0;
}