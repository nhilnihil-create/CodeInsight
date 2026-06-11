#include "bits/stdc++.h"
using namespace std;
const int MAX_INT = 1000000;
bool is_prime[MAX_INT + 1];
int prime[MAX_INT];

//エラトステネスの篩(素数の数を返している)
//11→2,3,5,7,11

int sieve(long long  n) {
	int p = 0;
	is_prime[0] = false;
	is_prime[1] = false;
	for (int m = 2; m <= n; ++m) {//初期化
		is_prime[m] = true;
	}

	for (int m = 2; m <= n; ++m) {
		if (is_prime[m]) {
			++p;
			prime[p] = m;
			for (int l = 2 * m; l <= n; l += m) {
				is_prime[l] = false;
			}
		}
	}
	return p;
}

int main() {
	sieve(100000);
	vector<int>sum(100000 + 1);
	for (int i = 1; i < 100000; ++i) {
		sum[i] = sum[i - 1];
		if (1 == i % 2) {
			if (is_prime[i] && is_prime[(i + 1) / 2]) {
				sum[i]++;
			}
		}
	}
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; ++i) {
		int l, r;
		cin >> l >> r;
		cout << sum[r] - sum[l - 1] << endl;
	}
	return 0;
}