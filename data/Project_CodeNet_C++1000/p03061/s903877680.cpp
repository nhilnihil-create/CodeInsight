#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

template <typename T>
T gcd(T a, T b) { return (b ? gcd(b, a % b) : a); }

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) { cin >> A[i]; }

	vector<int> dl(N, 0), dr(N, 0);
	dl[0] = A[0]; dr.back() = A.back();
	for (int i = 1; i < N; ++i) { dl[i] = gcd(dl[i - 1], A[i]); }
	for (int i = N - 2; i >= 0; --i) { dr[i] = gcd(dr[i + 1], A[i]); }

	int ans = max(dr[1], dl[N - 2]);
	for (int i = 1; i < N - 1; ++i) {
		ans = max(ans, gcd(dl[i - 1], dr[i + 1]));
	}
	cout << ans << "\n";
	
	return 0;
}
