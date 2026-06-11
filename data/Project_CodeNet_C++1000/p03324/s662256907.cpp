#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
	int D, N;
	cin >> D >> N;

	int plus = 1;
	int ans = 1;
	if (D == 1) {
		plus = 100;
		ans = 100;
	}
	else if (D == 2) {
		plus = 10000;
		ans = 10000;
	}

	for (int i = 1; i < N; ++i) {
		ans += plus;
	}

	if (N == 100) {
		ans += plus;
	}

	cout << ans << endl;
	return 0;
}