#include "bits/stdc++.h"
using namespace std;

//約数の個数
long long calc(long long N,long long M) {
	long long ret = 1;
	for (long long i = 2; i*i <= N; i++) {
		int m = 0;
		while (N%i == 0) { // 素数で割り切れなくなるまで割っていく
			m++;//割った個数を配列に足す
			N /= i;
		}
		if (0 != m) {
			for (int j = 0;j<m/M;++j) {
				ret *= i;
			}
		}
		if (1 == N) {
			break;
		}
	}
	if (1 != N) {
		for (int j = 0; j < 1 / M; ++j) {
			ret *= N;
		}
	}
	return ret;
}


int main() {
	long long N, P;
	cin >> N >> P;
	long long ans = calc(P,N);
	cout << ans <<  endl;
	return 0;
}
