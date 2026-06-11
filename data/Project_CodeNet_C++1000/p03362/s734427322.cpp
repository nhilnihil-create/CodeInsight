#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <string>
#include <set>
#include <cassert>

using namespace std;

vector<int> primes;

vector<int> make_primes(int n) {
	vector<bool> is_prime(n + 1, true);
	is_prime[0] = is_prime[1] = false;

	for (int i = 2; i * i <= n; i++) {
		if (is_prime[i]) {
			for (int j = i * i; j <= n; j += i) {
				is_prime[j] = false;
			}
		}
	}

	vector<int> primes = {2};
	for (int i = 3; i <= n; i += 2) {
		if (is_prime[i]) {
			primes.emplace_back(i);
		}
	}

	return n < 2 ? vector<int>() : primes;
}


int main() {
	int n;
	cin >> n;

	primes = make_primes(55555);
	vector<int> ans;
	for (int i = 0; i < primes.size(); i++) {
		if (primes[i] % 5 == 1) {
			ans.emplace_back(primes[i]);
		}
		if (ans.size() == n) {
			break;
		}
	}

	for (int i = 0; i < n; i++) {
		if (i != 0) {
			cout << " ";
		}
		cout << ans[i];
	}
	cout << endl;
	return 0;
}
