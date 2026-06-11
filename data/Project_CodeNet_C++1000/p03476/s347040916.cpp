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
	int q;
	cin >> q;
	int l[q], r[q];
	int max = 0;
	for (int i = 0; i < q; i++) {
		cin >> l[i] >> r[i];
		if (max < r[i])
			max = r[i];
	}
	vector<bool> table;
	vector<long long> primes;
	eratosthenes(max, table, primes);
	int counts[max+1];
	counts[0] = 0;
	counts[1] = 0;
	counts[2] = 0;
	for (int i = 3; i <= max; i++) {
		counts[i] = counts[i-1];
		if (table[i] && table[(i+1)/2])
			counts[i]++;
	}
	for (int i = 0; i < q; i++) {
		cout << counts[r[i]] - counts[l[i]-1] << endl;
	}
	return 0;
}