#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int N, D, X;
	cin >> N >> D >> X;

	for (int i = 0; i < N; i++) {
		X++;
		int A;
		cin >> A;

		int n = A;
		while (n + 1 <= D) {
			X++;
			n += A;
		}
	}

	cout << X << endl;
}