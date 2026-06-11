#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int64_t N;
	cin >> N;

	int64_t m;
	m = INT64_MAX;
	for (int64_t i = 0; i < 5; i++) {
		int64_t n;
		cin >> n;
		m = min(n, m);
	}

	cout << (N + m - 1) / m + 4 << endl;
}