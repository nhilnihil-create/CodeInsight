#include <iostream>
#include <vector>

using namespace std;

int main()
{
	long long n, k;
	cin >> n >> k;
	vector<long long> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int b[60] = {};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 60; j++) {
			if ((a[i] >> j) & 1 == 1) {
				b[j]++;
			}
		}
	}

	long long x = 0;
	for (int i = 59; i >= 0; i--) {
		if ((1LL << i) <= k) {
			if (b[i] <= n - b[i]) {
				long long tmp = x | (1LL << i);
				if (tmp <= k) {
					x = tmp;
				}
			}
		}
	}

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		ans += x ^ a[i];
	}
	cout << ans << endl;

	return 0;
}