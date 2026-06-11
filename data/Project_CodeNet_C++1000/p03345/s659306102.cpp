#include "bits/stdc++.h"
using namespace std;
int main() {
	long long A, B, C, K; cin >> A >> B >> C >> K;
	long long num = 0;
	if (K % 2 == 0) {
		num = A - B;
	}
	else {
		num = B - A;
	}
	if (num > pow(10, 18)) {
		cout << "Unfair" << endl;
	}
	else cout << num << endl;
}