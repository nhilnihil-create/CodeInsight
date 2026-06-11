#include <bits/stdc++.h>
using namespace std;

long long from_1(long long n) {
	long long result=0;
	// cout << "n=" << n << "\n";
	n = n + 1;
	for (long long i = 1; i <= n; i = i * 2) {
		if (i == 1) {
			result = (n / 2) % 2;
			// cout << i << ":" << result << "\n";
		} else {
			result = result + i * (max(n % (i * 2) - i, (long long)0) % 2);
			// cout << i << ":" << (max(n % (i * 2) - i, (long long)0) % 2) <<
			// "\n";
		}
	}
	// cout << "result" << result << "\n";
	return result;
}

int main() {
	// cin.tie(0);
	// ios::sync_with_stdio(false);

	long long A, B;
	scanf("%lld %lld", &A, &B);

	cout << (from_1(B) ^ from_1(A - 1));

	return 0;
}