#include <iostream>

using namespace std;

int main() {
	long long n; cin >> n;
	long long ans = 0;
	for (long long i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			long long m = n / i - 1;
          	if (m == 0) continue;
			if (n / m == n % m) ans += m;
		}
	}
	cout << ans << endl;

	return 0;
}