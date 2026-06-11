#include <iostream>
using namespace std;

int sumOfDigits(int i) {
	int sum = 0;
	while (i > 0) {
		sum += (i % 10);
		i /= 10;
	}
	return sum;
}

int main() {
	int n, a, b;
	int sum = 0;
	cin >> n >> a >> b;
	for (int i = 1; i <= n; i++) {
		int tmp = sumOfDigits(i);
		if (a <= tmp && tmp <= b) {
			sum += i;
		}
	}
	cout << sum << endl;
}