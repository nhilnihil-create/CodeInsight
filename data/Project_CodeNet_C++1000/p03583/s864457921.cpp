#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> v;
	for (int i = 1; i <= 3500 && v.empty(); ++i) {
		for (int j = 1; j <= i && v.empty(); ++j) {
			long long p = 4 * i * j - N * i - N * j;
			long long q = 1LL * N * i * j;
			if (p > 0 && q % p == 0 && q / p <= 3500) {
				v = vector<int>({ i, j, int(q / p) });
			}
		}
	}
	cout << v[0] << ' ' << v[1] << ' ' << v[2] << endl;
	return 0;
}