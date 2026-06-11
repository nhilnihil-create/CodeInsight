#include <iostream>
using namespace std;

int main() {
	long long N;
	cin >> N;

	for (int h = 1; h <= 3500; h++) {
		for (int n = h; n <= 3500; n++) {
			long long bumbo = N * h * n;
			long long bunshi = 4ll * h * n - N * n - N * h;
			if (bunshi > 0 && bumbo % bunshi == 0) {
				cout << h << " " << n << " " << bumbo / bunshi << endl;
				return 0;
			}
		}
	}
}