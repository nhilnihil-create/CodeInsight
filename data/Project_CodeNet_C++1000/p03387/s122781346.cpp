#include "bits/stdc++.h"
using namespace std;
int main() {
	long long A, B, C;
	cin >> A >> B >> C;
	long long M = max({ A,B,C });
	long long sum;
	if (M % 2 == (A + B + C) % 2) {
		sum = M - A + M - B + M - C;
	}
	else {
		sum = M + 1 - A + M + 1 - B + M + 1 - C;
	}
	cout << sum / 2 << endl;
}
