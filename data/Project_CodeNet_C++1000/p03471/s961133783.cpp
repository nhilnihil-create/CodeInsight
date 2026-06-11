#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int main() {
	long long n, y;
	cin >> n >> y;

	int k = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n - i; j++) {
			k = n - i - j;
			if (1000 * i + 5000 * j + 10000 * k == y) {
				cout << k << " " << j << " " << i << endl;
				return 0;
			}
		}
	}

	cout << "-1 -1 -1\n";

	return 0;
}