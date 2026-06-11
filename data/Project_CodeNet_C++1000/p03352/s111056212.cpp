#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int X;
	cin >> X;

	int n = sqrt(X);
	int ans = n * n;

	for (int i = n - 1; i > 1; i--) {
		int m = 1;
		while (m <= X) {
			m *= i;
		}
		m /= i;
		ans = max(ans, m);
	}

	cout << ans << endl;
}