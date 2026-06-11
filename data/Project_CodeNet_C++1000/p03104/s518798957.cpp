#include <iostream>
using namespace std;

long long xor_sum(long long a) {
	long long res = 0;
	if (a % 2 == 0) {
		res ^= a;
		--a;
	}
	return res ^ ((a+1)%4/2);
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