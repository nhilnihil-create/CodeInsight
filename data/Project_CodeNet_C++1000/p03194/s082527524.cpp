#include <iostream>
#include <vector>
#include <cmath>

long ipow(long x, long e)
{
	long y = 1;
	while (e > 0) {
		if (e%2 == 1)
			y *= x;
		x *= x;
		e /= 2;
	}
	return y;
}

std::vector<long> make_prime_table(long P, long N) // PのN乗根以下の素数のテーブルを作る
{
	long pmax = std::pow(P, 1.0/N) + 2;
//	std::cout << "make prime to " << pmax << "\n";
	std::vector<long> ret;

	ret.push_back(2);
	for (long i = 3; i <= pmax; i += 2) {
		long sqrti = std::sqrt((double)i) + 1;
		int j = 0;
		for (; j < ret.size(); ++j) {
			if (ret[j] > sqrti)
				break;
			if (i % ret[j] == 0)
				goto next;
		}
		ret.push_back(i);
	next:
		NULL;
	}

	return ret;
}

int main()
{
	long N, P;
	std::cin >> N >> P;
	long result = 1;

	if (N >= 63) {
		std::cout << "1\n";
		return 0;
	}
	if ((1 << N) > P) {
		std::cout << "1\n";
		return 0;
	}
	if (N == 1) {
		std::cout << P << "\n";
		return 0;
	}

	auto primes = make_prime_table(P, N);
//	for (auto x : primes)
//		std::cout << x << ", ";
//	std::cout << "\n";

	long p = P;
	for (auto it = primes.begin(); it != primes.end(); ++it) {
		long v = ipow(*it, N);
		if (p < v)
			break;
		while (p % v == 0) {
			p /= v;
			result *= *it;
		}
	}
	std::cout << result << "\n";
}