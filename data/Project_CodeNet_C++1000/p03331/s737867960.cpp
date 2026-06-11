// AGC025A - Digits Sum

#include <bits/stdc++.h>
using namespace std;

int SumOfDigits(int n) {
	int ans = 0;

	while (n > 0) {
		ans += n % 10;
		n /= 10;
	}

	return ans;
}

int main() {
	int N;
	cin >> N;

	int minT = 1000;
	for (int i = 1; i < N; i++) {
		int temp;
		temp = SumOfDigits(i) + SumOfDigits(N - i);
		minT = min(minT, temp);
	}

	cout << minT << endl;

	return 0;
}
