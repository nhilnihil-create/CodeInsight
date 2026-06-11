#include "bits/stdc++.h"
using namespace std;

//約数の個数
long long calc(long long N) {
	vector<long long> x;
	for (long long i = 2; i*i <= N; i++) {
		int m = 0;
		while (N%i == 0) { // 素数で割り切れなくなるまで割っていく
			m++;//割った個数を配列に足す
			N /= i;
		}
		if (0 != m) {
			x.push_back(m);
		}
		if (1 == N) {
			break;
		}
	}
	if (1 != N) {
		x.push_back(1);
	}

	long long nAns = 1;
	for (long long n = 0; n < x.size(); ++n) {
		nAns *= x[n] + 1;
	}
	return nAns;
}

int main() {
	int N;
	cin >> N;
	int ans = 0;
	for (int i = 1; i <= N; i += 2) {
		if (8 == calc(i)) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}