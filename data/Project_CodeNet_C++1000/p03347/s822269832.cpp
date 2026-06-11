#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> a(N);
	for (int i = 0; i < N; ++i) { cin >> a[i]; }

	bool ok = (a[0] == 0);
	for (int i = 1; i < N; ++i) {
		if (a[i] > a[i - 1]) {
			ok = ok && (a[i] == a[i - 1] + 1);
		}
	}

	if (!ok) {
		cout << -1 << endl;
		return 0;
	}

	a.push_back(-1);
	Int ans = 0;
	for (int i = 0; i + 1 < a.size(); ++i) {
		if (a[i] >= a[i + 1]) { ans += a[i]; }
	}
	cout << ans << endl;

	return 0;
}
