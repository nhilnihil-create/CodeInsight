#include <iostream>
#include <vector>
using namespace std;

vector<bool> make_primes(int n) {
	vector<bool> is_prime(n + 1, true);
	is_prime[0] = false;
	is_prime[1] = false;
	for (int i = 2; i <= n; ++i) {
		for (int j = i * 2; j <= n; j += i) {
			is_prime[j] = false;
		}
	}
	return is_prime;
}

int main() {
	int n;
	cin >> n;

	vector<bool> is_prime = make_primes(100000);
    bool is_like_2017[100001];
	for (int i = 0; i <= 100000; ++i) {
		is_like_2017[i] = is_prime[i] && is_prime[(i + 1) / 2];
	}

    int sum[100002];
	sum[0] = 0;
	for (int i = 0; i <= 100000; ++i) {
		sum[i + 1] = sum[i];
		if (is_like_2017[i]) {
			sum[i + 1]++;
		}
	}

	for (int i = 0; i < n;  ++i) {
		int l, r;
		cin >> l >> r;

		cout << sum[r + 1] - sum[l] << endl;
	}

	return 0;
}