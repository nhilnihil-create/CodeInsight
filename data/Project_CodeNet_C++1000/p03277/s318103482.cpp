#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) cin >> A[i];
	int L = *min_element(A.begin(), A.end()) - 1, R = *max_element(A.begin(), A.end()) + 1;
	while (R - L > 1) {
		int M = (L + R) >> 1;
		vector<int> bit(2 * N + 2);
		int cur = N; long long sum = 0;
		for (int i = N + 1; i <= 2 * N + 1; i += i & (-i)) ++bit[i];
		for (int i = 0; i < N; ++i) {
			if (A[i] <= M) ++cur;
			else --cur;
			for (int j = cur; j >= 1; j -= j & (-j)) sum += bit[j];
			for (int j = cur + 1; j <= 2 * N + 1; j += j & (-j)) ++bit[j];
		}
		if (sum * 2 > 1LL * N * (N + 1) / 2) R = M;
		else L = M;
	}
	cout << R << endl;
	return 0;
}