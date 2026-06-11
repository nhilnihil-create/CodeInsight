#include <bits/stdc++.h>
using namespace std;

long long cube(int n) {
	return (long long) n * n * n;
}

int main() {
	int n, k;
	cin >> n >> k;
	long long ans;
	if (k % 2) {
		ans = cube(n / k);
	} else {
		ans = cube(n / (k / 2) / 2) + cube((n / (k / 2) + 1) / 2);
	}

	cout << ans << endl;
}
