#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> p;
	vector<bool> sieve(n + 1, 1);
	for (int i = 2; i < n; i++) {
		if (!sieve[i])
			continue;
		p.emplace_back(i);
		for (int j = i * i; j < n; j += i)
			sieve[j] = 0;
	}
	vector<int> b(p.size());
	for (int i = 0, m; i < (int) p.size(); i++) {
		m = n;
		while (m > 0) {
			b[i] += m / p[i];
			m /= p[i];
		}
	}

	vector<int> c(98);
	for (int i = 0; i < (int) p.size(); i++) {
		for (int j = 2; j <= b[i]; j++) {
			c[j]++;
		}
	}

	int result = 0;
	result += c[74];
	result += c[24] * (c[2] - 1);
	result += c[14] * (c[4] - 1);
	result += c[4] * (c[4] - 1) / 2 * (c[2] - 2);
	cout << result << endl;

}
