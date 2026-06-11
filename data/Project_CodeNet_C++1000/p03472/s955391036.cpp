
// D - Katana Thrower

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int b[100000];

int main() {
	int N, H;
	cin >> N >> H;

	int max_a = 0;
	for (int i=0; i<N; i++) {
		int a;
		cin >> a >> b[i];
		max_a = max(max_a, a);
	}

	sort(b, b+N, greater<int>());
	int max_b = b[0];

	int ans = 0;

	for (int i=0; i<N; i++) {
		if (b[i] <= max_a || H <= 0) break;
		H -= b[i];
		ans++;
	}

	if (H > 0) {
		ans += (H - 1) / max_a + 1;
	}

	cout << ans << endl;

	return 0;
}