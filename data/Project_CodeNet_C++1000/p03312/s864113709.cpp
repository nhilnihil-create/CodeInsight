#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<long long> a(n + 1);
	vector<long long> pre(n + 1);
	vector<long long> suf(n + 1);
	vector<int> cut_pre(n + 1);
	vector<int> cut_suf(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + a[i];
		suf[i] = suf[i - 1] + a[n + 1 - i];
	}
	for (int j = 0, i = 1; i <= n; i++) {
		while (j < i && pre[j + 1] * 2 <= pre[i]) j++;
		cut_pre[i] = j;
	}
	for (int j = 0, i = 1; i <= n; i++) {
		while (j < i && suf[j + 1] * 2 <= suf[i]) j++;
		cut_suf[i] = j;
	}
	long long ans = 1LL<<60;
	for (int i = 2; i <= n - 2; i++) {
		for (int j = cut_pre[i]; j <= cut_pre[i] + 1 && j <= i - 1; j++) {
			for (int k = cut_suf[n - i]; k <= cut_suf[n - i] + 1 && k <= n - i - 1; k++) {
				long long b = pre[j], c = pre[i] - pre[j];
				long long d = suf[k], e = suf[n - i] - suf[k];
				long long maxv = max(max(c, b), max(e, d));
				long long minv = min(min(c, b), min(e, d));
				ans = min(ans, maxv - minv);
			}
		}
	}
	cout << ans << endl;
	return 0;
}