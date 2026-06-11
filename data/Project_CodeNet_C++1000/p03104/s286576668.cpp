#include <iostream>
#define int long long
using namespace std;

//(4x + 0)～(4x + 3)のxorは0
int f(int n) {
	if (n <= 0) return 0;
	int ret = 0;
	for (int i = (n / 4) * 4; i <= n; i++) {
		ret ^= i;
	}
	return ret;
}

signed main() {
	int a, b;
	cin >> a >> b;
	cout << (f(b) ^ f(a - 1)) << endl;
	return 0;
}