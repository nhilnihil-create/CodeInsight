#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int64_t GCD(int64_t a, int64_t b) {
	if (!b) return a;
	else return GCD(b, a % b);
}

int main() {
	int64_t N, X;
	cin >> N >> X;

	vector<int64_t> d(N);
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		d[i] = abs(n - X);
	}

	int64_t ans = d[0];
	for (int i = 1; i < d.size(); i++) {
		ans = GCD(ans, d[i]);
	}

	cout << ans << endl;
}