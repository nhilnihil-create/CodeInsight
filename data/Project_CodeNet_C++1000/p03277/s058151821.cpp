#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
long long solve(int l, int r, vector<int> &v) {
	if (r - l == 1) return 0;
	int m = (l + r) >> 1;
	long long lc = solve(l, m, v);
	long long rc = solve(m, r, v);
	int ptr = l;
	long long subans = 0;
	for (int i = m; i < r; ++i) {
		while (ptr != m && v[ptr] < v[i]) ++ptr;
		subans += ptr - l;
	}
	vector<int> vmerged(r - l);
	merge(v.begin() + l, v.begin() + m, v.begin() + m, v.begin() + r, vmerged.begin());
	copy(vmerged.begin(), vmerged.end(), v.begin() + l);
	return lc + rc + subans;
}
int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	long long P = (long long)(N) * (N + 1) / 2;
	int L = 0, R = 1000000001;
	while (R - L > 1) {
		int M = (L + R) >> 1;
		vector<int> S(N + 1);
		for (int i = 0; i < N; ++i) {
			S[i + 1] = S[i] + (A[i] <= M ? 1 : -1);
		}
		long long res = solve(0, N + 1, S);
		if (res > P / 2) R = M;
		else L = M;
	}
	cout << R << endl;
	return 0;
}