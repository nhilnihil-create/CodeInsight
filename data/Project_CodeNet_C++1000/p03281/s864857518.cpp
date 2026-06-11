#include <iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	int answer = 0;
	for (int C = 1; C <= N; C += 2) {
		int num_of_divisors = 0;
		for (int X = 1; X <= C; ++X) {
			if (C % X == 0) {
				++num_of_divisors;
			}
		}
		if (num_of_divisors == 8) {
			++answer;
		}
	}
	cout << answer << '\n';
	return 0;
}
