#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>
#include <numeric>

using namespace std;

int main() {
	long long int N, P;
	int max_gcd = 1;
	int start_num = 0;

	cin >> N >> P;

	if (N == 1) {
		cout << P << endl;
	} else {

		for (int i = 1;; i *= 10) {
			if (pow(i, N) > P) {
				start_num = i;
				break;
			}
		}

		for (long long int i = start_num; i != 1; i--) {
			if (P % (long long int) pow(i, N) == 0) {
				max_gcd = i;
				break;
			}
		}

		cout << max_gcd << endl;
	}
}
