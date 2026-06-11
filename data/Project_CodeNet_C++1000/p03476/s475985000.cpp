#include <bits/stdc++.h>

void Sieve(int N, std::vector<bool>& prime)
{
	prime.assign(N, true);
	prime[0] = prime[1] = false;
	for (int loop = 2; loop * loop < N; ++loop) {
		if (prime[loop]) {
			for (int loop2 = loop * 2; loop2 < N; loop2 += loop) {
				prime[loop2] = false;
			}
		}
	}
}

int main()
{
	std::vector<bool>prime;
	const int N = 100000;
	Sieve(N, prime);

	std::vector<int> x(N);
	for (int loop = 1; loop < N; loop += 2) {
		if (prime.at(loop) && prime.at((loop + 1) / 2)) {
			x[loop] = 1;
		}
	}

	for (int loop = 1; loop < N; ++loop) {
		x[loop] += x[loop - 1];
	}

	int Q;
	std::cin >> Q;
	for (int loop = 0; loop < Q; ++loop) {
		int l, r;
		std::cin >> l >> r;
		std::cout << x[r] - x[l - 1] << std::endl;
	}

	return 0;
}
