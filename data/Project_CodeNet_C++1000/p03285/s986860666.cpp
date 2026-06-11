#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int N;
	cin >> N;

	for (int i = 0; i <= (N / 7); i++) {
		for (int j = 0; j <= (N / 4); j++) {
			int n = 7 * i + 4 * j;
			if (n == N) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
}