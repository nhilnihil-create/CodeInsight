#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int N, M;
	cin >> N >> M;

	int n = 1;
	for (int i = 0; i < M; i++) {
		n *= 2;
	}

	int ans = 1900 * M + 100 * (N - M);
	ans *= n;

	cout << ans << endl;
}