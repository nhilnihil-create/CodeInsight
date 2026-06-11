#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
using namespace std;

const int MAX = 200010;
const unsigned long long INF = 1ULL << 63;

int main() {
	unsigned long long N, X;
	unsigned long long x[MAX];
	unsigned long long sum[MAX] = { 0 };
	unsigned long long ans = INF;

	cin >> N >> X;
	for (int i = 0; i < N; i++) {
		cin >> x[i];
		sum[i + 1] = x[i] + sum[i];
	}

	for (int i = 1; i <= N; i++) {
		int pos = N - i;
		unsigned long long s = (sum[pos + i] - sum[pos]) * 5;
		unsigned long long c = 5;

		while (pos >= i) {
			s += (sum[pos] - sum[pos - i]) * c;
			c += 2;
			pos -= i;
		}

		if (pos != 0)s += sum[pos] * c;
		s += X * i + X * N;

		ans = min(ans, s);
	}

	cout << ans << endl;

	return 0;
}