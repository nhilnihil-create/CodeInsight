#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
	int N; cin >> N;
	vector<int> A_plus_B(N);
	ll res = 0;
	for (int i = 0; i < N; ++i) {
		int a, b; cin >> a >> b;
		A_plus_B[i] = a + b;
		res -= b;
	}
	sort(A_plus_B.begin(), A_plus_B.end());
	for (int i = 0; i < N; ++i) {
		if (i & 1) continue;
		else res += A_plus_B[N - 1 - i];
	}
	cout << res << endl;
	return 0;
}