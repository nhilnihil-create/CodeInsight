#include <iostream>

using namespace std;


int main() {
	int N, A, B;
	cin >> N >> A >> B;

	int b = 1;
	int c = 0;
	int sum = 0;

	for (int i = 1; i <= N; i++) {
		b = i;
		c = i;
		int a = 0;
		while (b > 0) {
			a += b % 10;
			b /= 10;
		}
		if (a >= A && a <= B) {
			sum += c;
		}
	}

	cout << sum << endl;


	return 0;
}