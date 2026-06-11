#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
	int N;
	cin >> N;

	int ans = 0;
	for (int i = 0; i < N; ++i) {
		int a;
		cin >> a;

		ans += (a - 1);
	}

	cout << ans << endl;
	return 0;
}
