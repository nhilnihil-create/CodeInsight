#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	
	int n, k; cin >> n >> k;
	vector<ll> num(k, 0);
	for (int i = 1; i <= n; i++) {
		num[i % k]++; // 1 ～ n を mod k の世界に変換
	}
	ll ans = 0;
	for (int a = 0; a < k; a++) {
		int b = (k - a) % k;
		int c = (k - a) % k;
		if ((b + c) % k == 0) {
			ans += num[a] * num[b] * num[c];
		}
	}
	cout << ans << endl;
	return 0;
}