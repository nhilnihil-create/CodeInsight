#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int N;
	cin >> N;

	int sum = 0, m = 0;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		sum += n;
		m = max(m, n);
	}

	cout << sum - (m / 2) << endl;
}