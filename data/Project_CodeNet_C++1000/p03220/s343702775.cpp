#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int N, T, A;
	cin >> N >> T >> A;

	double d = INF, h = -1;
	for (int i = 0; i < N; i++) {
		int H;
		cin >> H;
		double n = (double)T - H * 0.006;
		double m = abs(A - n);
		if (m < d) {
			d = m;
			h = i + 1;
		}
	}

	cout << h << endl;
}