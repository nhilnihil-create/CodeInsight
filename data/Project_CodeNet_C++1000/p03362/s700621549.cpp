#include <bits/stdc++.h>
using namespace std;
// O(n loglog n)
void eratosthenes(long long n, vector<bool>& table, vector<long long>& primes)
{
	table.resize(n+1);
	fill(table.begin(), table.end(), true);
	if (n >= 0)
		table[0] = false;
	if (n >= 1)
		table[1] = false;
	for (int i = 2; i*i <= n; i++) {
		if (table[i] == false)
			continue;
		for (int j = i+i; j <= n; j+=i) {
			table[j] = false;
		}
	}
	for (int i = 0; i < n+1; i++) {
		if (table[i])
			primes.push_back(i);
	}
}
int main(void)
{
	int n;
	cin >> n;
	vector<bool> table;
	vector<long long> primes;
	eratosthenes(55555, table, primes);
	vector<long long> p1, p2, p3, p4;
	for (int i = 0; i < primes.size(); i++) {
		if (primes[i]%5 == 1)
			p1.push_back(primes[i]);
		else if (primes[i]%5 == 2)
			p2.push_back(primes[i]);
		else if (primes[i]%5 == 3)
			p3.push_back(primes[i]);
		else if (primes[i]%5 == 4)
			p4.push_back(primes[i]);
	}
	for (int i = 0; i < 4; i++) {
		switch (i) {
			case 0:
				if (p1.size() >= n) {
					for (int i = 0; i < n; i++)
						printf("%lld ", p1[i]);
					cout << endl;
					return 0;
				}
				break;
			case 1:
				if (p2.size() >= n) {
					for (int i = 0; i < n; i++)
						printf("%lld ", p2[i]);
					cout << endl;
					return 0;
				}
				break;
			case 2:
				if (p3.size() >= n) {
					for (int i = 0; i < n; i++)
						printf("%lld ", p3[i]);
					cout << endl;
					return 0;
				}
				break;
			case 3:
				if (p4.size() >= n) {
					for (int i = 0; i < n; i++)
						printf("%lld ", p4[i]);
					cout << endl;
					return 0;
				}
				break;
		}
	}
	return 0;
}