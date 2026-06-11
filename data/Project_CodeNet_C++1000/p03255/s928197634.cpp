#include <iostream>
#include <algorithm>
using namespace std;

long long N, X, A[200009], B[200009], minx = (1LL << 60);

long long ranges(int l, int r) {
	return B[r] - B[l - 1];
}

int main() {
	cin >> N >> X;
	for (int i = 1; i <= N; i++) { cin >> A[i]; B[i] = A[i]; }
	for (int i = 1; i <= N; i++) B[i] += B[i - 1];

	for (int i = 1; i <= N; i++) {
		long long sum = 0, cx = N, ret = 3;
		while (cx >= 1) {
			long long L = cx - i + 1, R = cx; L = max(L, 1LL);
			sum += ranges(L, R)*max(5LL, ret); ret += 2; if (sum >= (1LL << 60)) sum = (1LL << 60);
			cx = L - 1;
		}
		minx = min(minx, sum + 1LL * (N + i) * X);
	}
	cout << minx << endl;
	return 0;
}