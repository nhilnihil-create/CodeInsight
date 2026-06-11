#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int isPrime(int num) {
	if (num <= 1) return 0;
	for (int i = 2; i < num; i++) {
		if (num%i == 0) return 0;
	}
	return 1;
}

int main() {
	int q, l, r;
	int sum[100010] = { 0 };
	for (int i = 1; i <= 100000; i++) {
		sum[i] = sum[i - 1] + (isPrime(i) && isPrime((i + 1) / 2));
	}
	cin >> q;
	rep(i, q) {
		cin >> l >> r;
		cout << sum[r] - sum[l - 1] << endl;
	}
	return 0;
}