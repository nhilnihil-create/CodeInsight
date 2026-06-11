#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

#undef INT_MIN
#undef INT_MAX
#define INT_MIN -2147483648
#define INT_MAX 2147483647

int main() {
	int N, Y;
	cin >> N >> Y;

	for (int i = 0; i <= N; ++i) {
		for (int j = 0; j <= N; ++j) {
			for (int k = 0; k <= N; ++k) {
				if (N < i + j + k)break;
				int bill1 = i * 1000, bill2 = j * 5000, bill3 = k * 10000;
				if (N == i + j + k && bill1 + bill2 + bill3 == Y) {
					cout << k << " " << j << " " << i << endl;
					return 0;
				}
			}
		}
	}

	cout << -1 << " " << -1 << " " << -1 << endl;
	return 0;
}