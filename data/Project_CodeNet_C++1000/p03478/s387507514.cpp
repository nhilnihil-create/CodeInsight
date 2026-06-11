#include <bits/stdc++.h>
# define M_PI           3.14159265358979323846  /* pi */
using namespace std;

int main() {
	int N, A, B;
	cin >> N >> A >> B;
	int k = 0;
	int j = 0;
	int result = 0;

	for (int i = 1; i <= N; i++) {
		k = i;

		while (true) {
			if (k < 10) {
				j += k % 10;
				break;
			}
			j += k % 10;
			k = k / 10;
		}

		if (A <= j && j <= B) {
			result += i;
		}
		j = 0;
		k = 0;
	}
	cout << result << endl;
}