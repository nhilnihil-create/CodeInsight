#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

int main() {
	int X, Y, Z, K;
	cin >> X >> Y >> Z >> K;
	vector<Int> A(X), B(Y), C(Z);
	for (int i = 0; i < X; ++i) { cin >> A[i]; }
	for (int i = 0; i < Y; ++i) { cin >> B[i]; }
	for (int i = 0; i < Z; ++i) { cin >> C[i]; }

	vector<Int> AB;
	for (auto a : A) {
		for (auto b : B) { AB.emplace_back(a + b); }
	}

	sort(AB.rbegin(), AB.rend());
	vector<Int> ans;
	for (int i = 0; i < min((int)AB.size(), K); ++i) {
		for (auto c : C) { ans.emplace_back(AB[i] + c); }
	}

	sort(ans.rbegin(), ans.rend());
	for (int i = 0; i < K; ++i) { cout << ans[i] << endl; }

	return 0;
}
