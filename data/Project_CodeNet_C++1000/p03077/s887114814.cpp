#include "bits/stdc++.h"
using namespace std;

int main() {
	long long N;
	cin >> N;
	long long small;
	for (int n = 0;n<5;++n) {
		long long num;
		cin >> num;
		if (0==n) {
			small = num;
		}
		else {
			small = min(small, num);
		}
	}
	long long ans = 5;
	ans--;
	ans += N / small;
	if (0 != N%small) {
		ans++;
	}
	cout << ans << endl;
}
