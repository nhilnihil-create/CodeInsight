#include<iostream>

using namespace std;

int main() {
	int N, A, B, Asum, Bsum, min=1999999;

	cin >> N;

	for (int i = 1; i <= N; i++) {
		A = i;
		B = N - A;
		if (B > 0) {
			Asum = A % 10 + A / 10 % 10 + A / 100 % 10 + A / 1000 % 10 + A / 10000 % 10 + A / 100000 % 10;
			Bsum = B % 10 + B / 10 % 10 + B / 100 % 10 + B / 1000 % 10 + B / 10000 % 10 + B / 100000 % 10;
			if (min > Asum + Bsum) {
				min = Asum + Bsum;
			}
		}
	}
	cout << min << endl;

	return 0;
}