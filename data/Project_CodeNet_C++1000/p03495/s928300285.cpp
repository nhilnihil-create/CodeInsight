#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

int cnt[220000];

int main() {
	int n, k, a;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a;
		cnt[a - 1]++;
	}
	sort(cnt, cnt + n);
	int ans = 0;
	for (int i = 0; i < n - k; i++)
		ans += cnt[i];
	cout << ans << endl;
}