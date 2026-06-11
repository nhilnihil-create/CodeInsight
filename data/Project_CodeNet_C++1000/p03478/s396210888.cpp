#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
	int N, A, B;
	cin >> N >> A >> B;

	int ans = 0;
	for (int i = 1; i <= N; ++i) {
		int div = i;
		int sum = 0;
		while (div != 0) {
			int mod = div % 10;
			sum += mod;
			div = div / 10;
		}

		if (A <= sum && sum <= B) {
			ans += i;
		}
	}

	cout << ans << endl;
	return 0;
}
