#include<iostream>

using namespace std;

int main() {
	long long int A, B, C, X, Y;
	long long int a, b, ab, min = 999999999999, sum, max;

	cin >> A >> B >> C >> X >> Y;
	
	if (X > Y) {
		max = X;
	}
	else {
		max = Y;
	}

	for (int i = 0; i <= max*2; i += 2) {
		ab = i;
		a = X - ab / 2;
		b = Y - ab / 2;
		if (a < 0) {
			a = 0;
		}
		if (b < 0) {
			b = 0;
		}
		sum = a * A + b * B + ab * C;
		if (min > sum) {
			min = sum;
		}
	}
	cout << min << endl;

	return 0;
}