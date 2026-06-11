#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int N, Y;
	cin >> N >> Y;

	bool f = false;

	for (int i = 0; i <= Y / 10000; i++) {
		for (int j = 0; j <= Y / 5000; j++) {
			if (i + j > N) break;

			int k = N - i - j;
			if (i + j + k == N) {
				int sum = 10000 * i + 5000 * j + 1000 * k;
				if (sum == Y) {
					cout << i << ' ' << j << ' ' << k << endl;
					return 0;
				}
			}
		}
	}

	cout << -1 << ' ' << -1 << ' ' << -1 << endl;
}