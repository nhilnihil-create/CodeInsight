#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

#undef INT_MIN
#undef INT_MAX
#define INT_MIN -2147483648
#define INT_MAX 2147483647

int main() {
	long long N, M;
	cin >> N >> M;

	long long countTails = 0;
	if (N == 1 && M == 1) {
		countTails = 1;
	}
	else if (N < 3 && M < 3 || (N == 2 || M == 2)) {
		countTails = 0;
	}
	else {
		countTails = max(1ll, N - 2) * max(1ll, M - 2);
	}

	cout << countTails << endl;

	return 0;
}