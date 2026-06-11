#include "bits/stdc++.h"
using namespace std;

int main() {
	long long A, B, C;
	cin >> A >> B;
	C = B - A;
	cout << C * (C - 1) / 2 - A << endl;
}
