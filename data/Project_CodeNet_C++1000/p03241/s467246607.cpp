#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int N, M;
	cin >> N >> M;

	for (int i = M / N; i > 0; i--) {
		int n = M / i;
		if (n * i == M) {
			cout << i << endl;
			return 0;
		}
	}
}