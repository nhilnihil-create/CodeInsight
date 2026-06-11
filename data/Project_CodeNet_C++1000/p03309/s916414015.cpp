#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<long long>A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
		A[i] -= (i + 1);
	}
	sort(A.begin(), A.end());
	long long ans = 0;
	long long b = A[N / 2];
	for (int i = 0; i < N; ++i) {
		ans += abs(A[i] - b);
	}
	cout << ans << endl;
}
