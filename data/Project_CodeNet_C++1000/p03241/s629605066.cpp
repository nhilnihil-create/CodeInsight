#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	long long n, m;
	cin >> n >> m;
	vector<int> a;
	for (long long i = 1; i * i <= m; i++) {
		if (m % i == 0) {
			a.emplace_back(i);
			a.emplace_back(m / i);
		}
	}
	sort(a.rbegin(), a.rend());

	for (int i = 0; i < a.size(); i++) {
		if (a[i] * n <= m) {
			cout << a[i] << endl;
			return 0;
		}
	}

	return 0;
}