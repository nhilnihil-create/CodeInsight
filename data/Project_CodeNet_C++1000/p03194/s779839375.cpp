#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<cmath>
using namespace std;

unordered_map<long long, long long> factorization(long long n)
{
	unordered_map<long long, long long> ret;
	for (long long i = 2; i <= ceil(sqrt(n)); i++)
	{
		while (n % i == 0)
		{
			n = n / i;
			ret[i] += 1;
		}
	}

	ret[n] += 1;

	return ret;
}

int main(void)
{
	long long N, P;
	cin >> N >> P;

	auto mp= factorization(P);

	long long gcd = 1;

	for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
			

		for(int i = 0;i< itr->second / N ;i++){
			gcd *= itr->first;
		}
	}
	cout << gcd;

	return 0;
}
