#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

int main() {
	int N;
	cin >> N;
	Int sum = 0;
	Int minB = 1e18;
	for (int i = 0; i < N; ++i) {
		Int a, b;
		cin >> a >> b;
		sum += a;
		if (a > b) { minB = min(minB, b); }
	}
	cout << max((Int)0, sum - minB) << endl;

	return 0;
}
