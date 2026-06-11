#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	static long long A[200000], B[200000], BIT[30] = {}, ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < N; i++) cin >> B[i];
	for (int i = 0; i < 29; i++) {
		vector<int> X, Y;
		int P = pow(2, i);
		for (int j = 0; j < N; j++) X.emplace_back(A[j] % (P * 2)), Y.emplace_back(B[j] % (P * 2));
		sort(Y.begin(), Y.end());
		for (int j = 0; j < N; j++) {
			BIT[i] += (lower_bound(Y.begin(), Y.end(), 2 * P - X[j]) - lower_bound(Y.begin(), Y.end(), P - X[j]));
			BIT[i] += (lower_bound(Y.begin(), Y.end(), 4 * P - X[j]) - lower_bound(Y.begin(), Y.end(), 3 * P - X[j]));
		}
	}
	for (long long i = 0; i < 30; i++) {
		ans += pow(2, i) * (BIT[i] % 2);
	}
	cout << ans;
}