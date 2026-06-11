#include <iostream>
using namespace std;

long long pow2(int n) {
	return (1ll << n);
}

long long num_of_ones(long long x, int d) {
	long long a = pow2(d), b = pow2(d+1);
	return x / b * a + x % b / a * (x%a + 1);
}

long long xor_sum(long long x) {
	long long res = 0;
	for (int d = 0; d < 60; d++) {
		if (num_of_ones(x,d) % 2 == 1) res += pow2(d);
	}
	return res;
}

int main() {
	long long a, b;
	cin >> a >> b;
	long long ans;
	if (a == 0) ans = xor_sum(b);
	else ans = xor_sum(b) ^ xor_sum(a-1);
	cout << ans << endl;
	return 0;
}