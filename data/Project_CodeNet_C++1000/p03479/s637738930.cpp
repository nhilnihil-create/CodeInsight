
// C - Multiple Gift

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	ll X, Y;
	cin >> X >> Y;

	int ans = 1;

	ll A = X;
	while (1) {
		A *= 2;
		if (A > Y) break;
		ans++;
	}

	cout << ans << endl;

	return 0;
}