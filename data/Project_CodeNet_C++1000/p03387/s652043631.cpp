
// C - Same Integers

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	int X[3];
	cin >> X[0] >> X[1] >> X[2];

	int ans = 0;

	while(1) {
		sort(X, X+3);

		if (X[0] == X[1] && X[1] == X[2]) break;

		if (X[0] == X[1]) {
			X[0]++;
			X[1]++;
		} else if (X[1] - X[0] == 1) {
			X[0]++;
			X[2]++;
		} else {
			X[0] += 2;
		}

		ans++;
	}

	cout << ans << endl;

	return 0;
}