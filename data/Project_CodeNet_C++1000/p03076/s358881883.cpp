#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int d = 0, sum = 0;
	for (int i = 0; i < 5; i++) {
		int n;
		cin >> n;
		sum += n / 10 * 10;
		if (n % 10) {
			sum += 10;
			d = max(d, 10 - n % 10);
		}
	}

	cout << sum - d << endl;
}