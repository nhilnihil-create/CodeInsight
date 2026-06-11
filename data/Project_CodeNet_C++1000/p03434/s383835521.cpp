#include <iostream>
#include <algorithm>
using namespace std;

long long N, L[1000009];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> L[i];

	sort(L + 0, L + N);

	long long ret = 0;
	for (int i = N - 1; i >= 0; i -= 2) {
		if (i > 0) {
			ret += (L[i] - L[i - 1]);
		}
		else {
			ret += L[i];
		}
	}
	cout << ret << endl;

	return 0;
}