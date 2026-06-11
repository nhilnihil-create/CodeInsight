#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> av(n + 2, 0);
	vector<long long> rw(n + 2, 0);
	for (int i = 1; i <= n; ++i) {
		cin >> av[i];
		rw[i] = abs(av[i] - av[i - 1]) + rw[i - 1];
	}
	rw[n + 1] = abs(av[n + 1] - av[n]) + rw[n];

	for (int i = 1; i <= n; ++i) {
		cout << rw[n + 1] - (rw[i + 1] - rw[i - 1]) + abs(av[i + 1] - av[i - 1]) << endl;
	}

	return 0;
}