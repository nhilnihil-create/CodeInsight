#include <iostream>
#include <vector>

using namespace std;


int main() {
	int N, Y;
	cin >> N >> Y;
	int a, b, c;
	a = -1; b = -1; c = -1;

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			int k = N - i - j;
			if(k >= 0) {
				if (10000 * i + 5000 * j + 1000 * k == Y) {
					a = i;
					b = j;
					c = k;
				}
			}
		}
	}

	cout << a << " " << b << " " << c << endl;

	return 0;
}