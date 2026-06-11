#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int n;
	cin >> n;

	for (int i = 1; i < 10; i++) {
		int m = 111 * i;
		if (n <= m) {
			cout << m << endl;
			break;
		}
	}
}