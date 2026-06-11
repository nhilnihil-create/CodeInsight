#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	int value[220000] = {};
	int valueSize = 0;
	for (int i = 0; i < N; ++i) {
		int A;
		cin >> A;
		value[A]++;
		if (value[A] == 1) valueSize++;
	}

	sort(value, value + 220000);

	int i = 220000 - valueSize;
	int res = 0;
	while (K < valueSize) {
		res += value[i];
		++i;
		--valueSize;
	}
	
	cout << res << endl;
}