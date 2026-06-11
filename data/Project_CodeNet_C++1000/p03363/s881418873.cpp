#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<Int> A(N);
	for (int i = 0; i < N; ++i) { cin >> A[i]; }

	map<Int, Int> mp;
	mp[0] = 1;
	for (int i = 0; i < N; ++i) {
		if (i > 0) { A[i] += A[i - 1]; }
		++mp[A[i]];
	}

	Int ans = 0;
	for (auto it = mp.begin(); it != mp.end(); ++it) {
		Int x = it->second;
		ans += x * (x - 1) / 2;
	}
	cout << ans << "\n";

	return 0;
}
