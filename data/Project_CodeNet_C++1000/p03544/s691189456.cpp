#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main() {
	int64_t N;
	cin >> N;

	int64_t a = 1;
	int64_t b = 3;
	int64_t c;

	if (N != 1 && N != 2) {
		for (int i = 2; i < N; i++) {
			c = a + b;
			a = b;
			b = c;
		}

		cout << c << endl;
	}
	else {
		if (N == 1) {
			cout << "1" << endl;
		}
		else {
			cout << "3" << endl;
		}
	}
}