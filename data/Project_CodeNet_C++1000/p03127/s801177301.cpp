#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int GCD(int a, int b) {
	if (!b) return a;
	else {
		return GCD(b, a % b);
	}
}

int main() {
	int N;
	cin >> N;

	int ans = 0;
	for (int i = 0; i < N; i++) {
		int A;
		cin >> A;
		ans = GCD(ans, A);
	}

	cout << ans << endl;
}