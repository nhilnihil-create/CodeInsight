#include <iostream>
using namespace std;

int divisor(int input) {
	int count = 0;
	for (int i = 1; i <= input; i++) {
		if (input % i == 0) {
			count++;
		}
	}
	return count;
}

int main() {
	int n;
	cin >> n;
	int count = 0;
	for (int i = 1; i <= n; i += 2) {
		if (divisor(i) == 8) {
			count++;
		}
	}
	cout << count << endl;
}