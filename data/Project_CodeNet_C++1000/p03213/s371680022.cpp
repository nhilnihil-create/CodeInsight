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
	map<int, long long> m;
	eratosthenes(n, table, primes);
	for (int i = 2; i <= n; i++) {
		int tmpn = i;
		for (int j = 0; primes[j]*primes[j] <= tmpn; j++) {
			while (tmpn % primes[j] == 0) {
				tmpn /= primes[j];
				m[primes[j]]++;
			}
		}
		if (table[tmpn])
			m[tmpn]++;

	}
	long long ans = 0;
	long long count75 = 0, count3 = 0, count5 = 0, count15 = 0, count25 = 0;
	for (auto e : m) {
		//printf("%d: %d\n", e.first, e.second);
		if (e.second >= 74)
			count75++;
		if (e.second >= 2)
			count3++;
		if (e.second >= 4)
			count5++;
		if (e.second >= 14)
			count15++;
		if (e.second >= 24)
			count25++;
	}
	ans += count75;
	ans += (count3-1) * count25;
	ans += (count5-1) * count15;
	if (count5 >= 2)
		ans += (count3-2) * count5 * (count5-1)/2;
	cout << ans << endl;
	return 0;
}