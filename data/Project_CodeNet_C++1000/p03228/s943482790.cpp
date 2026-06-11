#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int A, B, K;
	cin >> A >> B >> K;

	for (int i = 0; i < K; i++) {
		if (i % 2 == 0) {
			if (A % 2) A--;
			B += A / 2;
			A /= 2;
		}
		else {
			if (B % 2) B--;
			A += B / 2;
			B /= 2;
		}
	}

	cout << A << ' ' << B << endl;
}